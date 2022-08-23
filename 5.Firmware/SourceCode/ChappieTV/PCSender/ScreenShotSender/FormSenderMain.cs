using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using System.Threading;
using System.Threading.Tasks;

namespace ScreenShotSender
{
    public partial class FormSenderMain : Form
    {
        CancellationTokenSource _cts;
        Task _task;
        FormCaptureBox formCaptureBox = new FormCaptureBox();
        ImageCodecInfo _jpgEncoder = null;
        Bitmap _resizeBmp;
        Bitmap _bmp;
        Graphics _gResizeBmp;
        EncoderParameters _encParams = new EncoderParameters(1);
        List<TextBox> _tbHosts = new List<TextBox>();
        List<TCPSender> _tcps = new List<TCPSender>();
        int _jpgQuality = 60;
        int _port = 63333;
        System.Diagnostics.Stopwatch _sw;
        Rectangle dstRect;
        int colcount = 1;
        int rowcount = 1;
        int _width = 160;
        int _height = 120;

        public FormSenderMain()
        {
            InitializeComponent();

            _sw = new System.Diagnostics.Stopwatch();
            _cts = new CancellationTokenSource();
            _task = Task.Run(() => { TaskMain(_cts.Token); });
        }

        private void FormSenderMain_FormClosed(object sender, FormClosedEventArgs e)
        {
            stop();
            _cts?.Cancel();
        }


        [DllImport("user32.dll")]
        extern static IntPtr GetWindowDC(IntPtr hwnd);
        [DllImport("gdi32.dll")]
        extern static int GetDeviceCaps(IntPtr hdc, int index);
        [DllImport("user32.dll")]
        extern static int ReleaseDC(IntPtr hwnd, IntPtr hdc);

        private void FormSenderMain_Shown(object sender, EventArgs e)
        {
            const int LOGPIXELSX = 88;
            const int LOGPIXELSY = 90;
            var dc = GetWindowDC(IntPtr.Zero);
            var dpiX = GetDeviceCaps(dc, LOGPIXELSX);
            var dpiY = GetDeviceCaps(dc, LOGPIXELSY);
            ReleaseDC(IntPtr.Zero, dc);

            foreach (ImageCodecInfo ici in ImageCodecInfo.GetImageEncoders()) {
                if (ici.FormatID == ImageFormat.Jpeg.Guid) {
                    _jpgEncoder = ici;
                    break;
                }
            }
            _jpgQuality = (int)nudQuality.Value;
            _encParams.Param[0] = new EncoderParameter(System.Drawing.Imaging.Encoder.Quality, _jpgQuality);

            formCaptureBox.Location = new Point(Location.X + 10, Location.Y + Height);
            FrameVisible(true);

            formCaptureBox.Width = 320 * dpiX / 96;
            formCaptureBox.Height = 240 * dpiY/ 96;

            tlpHost.RowStyles[0].Height = 18 * dpiY / 96;

            for (int i = 0; i < nudRow.Maximum * nudCol.Maximum; i++)
            {
                var tb = new TextBox();
                tb.Name = "tbHost" + i.ToString();
                tb.Parent = tlpHost;
                tb.Dock = DockStyle.Fill;
                tb.Text = "192.168.1.1";
                _tbHosts.Add(tb);
                _tcps.Add(new TCPSender());
            }
            for (int idx = 0; idx < 4; idx++)
            {
                var cs = new ColumnStyle();
                cs.SizeType = SizeType.Percent;
                cs.Width = tlpHost.ColumnStyles[0].Width;
                tlpHost.ColumnStyles.Add(cs);

                var rs = new RowStyle();
                rs.SizeType = tlpHost.RowStyles[0].SizeType;
                rs.Height = tlpHost.RowStyles[0].Height;
                tlpHost.RowStyles.Add(rs);
            }
            tlpHost.Height = (int)(tlpHost.RowCount * tlpHost.RowStyles[0].Height) + 3;

            timer1.Enabled = true;
        }

        private void nudCol_ValueChanged(object sender, EventArgs e)
        {
            tlpHost.ColumnCount = (int)nudCol.Value;
        }

        private void nudRow_ValueChanged(object sender, EventArgs e)
        {
            tlpHost.RowCount = (int)nudRow.Value;
            tlpHost.Height = (int)(tlpHost.RowCount * tlpHost.RowStyles[0].Height) + 3;
        }

        private void nudQuality_ValueChanged(object sender, EventArgs e)
        {
            _jpgQuality = (int)nudQuality.Value;
            _encParams.Param[0] = new EncoderParameter(System.Drawing.Imaging.Encoder.Quality, _jpgQuality);
        }

        private void FrameVisible(bool flg)
        {
            formCaptureBox.Visible = flg;
            btnShowFrame.Text = flg ? "HideBox" : "ShowBox";
        }

        private void btnShowFrame_Click(object sender, EventArgs e)
        {
            FrameVisible(!formCaptureBox.Visible);
            if (formCaptureBox.Visible) formCaptureBox.Focus();
        }

        private void btnStartStop_Click(object sender, EventArgs e)
        {
            if (_sw.IsRunning) stop();
            else start();
            FrameVisible(!_sw.IsRunning);
        }

        void start()
        {
            nudRow.Enabled = false;
            nudCol.Enabled = false;
            int idx = 0;
            for (int row = 0; row < nudRow.Value; row++)
            {
                for (int col= 0; col < nudCol.Value; col++)
                {
                    _tcps[idx].start(_tbHosts[idx].Text, _port);
                    idx++;
                }
            }
            _sw.Start();
            btnStartStopr.Text = "Disconnect";
        }

        void stop()
        {
            _sw?.Stop();
            foreach (var tcp in _tcps)
            {
                tcp?.stop();
            }
            btnStartStopr.Text = "Connect";
            nudRow.Enabled = true;
            nudCol.Enabled = true;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            var bmp = formCaptureBox.CaptureFrame();
            pbPreview.Image = bmp;
            _bmp = (Bitmap)bmp.Clone();

            _width = (int)nudWidth.Value;
            _height = (int)nudHeight.Value;
            colcount = (int)nudCol.Value;
            rowcount = (int)nudRow.Value;
        }

        private void TaskMain(CancellationToken ct)
        {
            while (!ct.IsCancellationRequested)
            {
                if (!_sw.IsRunning || _bmp == null) continue;

                dstRect.Width = _width;
                dstRect.Height = _height;
                float wid = _bmp.Width / (float)colcount;
                float hei = _bmp.Height / (float)rowcount;

                if (_resizeBmp == null || _resizeBmp.Width != _width || _resizeBmp.Height != _height)
                {
                    _gResizeBmp?.Dispose();
                    _resizeBmp?.Dispose();
                    _resizeBmp = new Bitmap(_width, _height, System.Drawing.Imaging.PixelFormat.Format24bppRgb);
                    _gResizeBmp = Graphics.FromImage(_resizeBmp);
                    _gResizeBmp.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.HighSpeed;
                }

                int idx = 0;
                float y = 0;
                for (int row = 0; row < rowcount; row++)
                {
                    float x = 0;
                    for (int col = 0; col < colcount; col++)
                    {
                        _gResizeBmp.DrawImage(_bmp, dstRect, x, y, wid, hei, GraphicsUnit.Pixel);
                        x += wid;
                        if (_sw.IsRunning) tcpJPGPrepare(_resizeBmp, _tcps[idx]);
                        idx++;
                    }
                    y += hei;
                }
            }
        }

            private void tcpJPGPrepare(Bitmap bmp, TCPSender tcp)
        {
            using (MemoryStream ms = new MemoryStream())
            {
                byte[] rgbValues = { 0 };
                ms.WriteByte(0x4A); // prefix "JPG" 3Byte
                ms.WriteByte(0x50);
                ms.WriteByte(0x47);
                ms.WriteByte(0);    // data len 4Byte
                ms.WriteByte(0);
                ms.WriteByte(0);
                ms.WriteByte(0);
                bmp.Save(ms, _jpgEncoder, _encParams);
                ms.Capacity = (int)ms.Length;
                rgbValues = ms.GetBuffer();
                {
                    UInt32 len = (UInt32)(ms.Length - 7);
                    rgbValues[3] = (byte)(len & 0xFF);
                    rgbValues[4] = (byte)((len >> 8) & 0xFF);
                    rgbValues[5] = (byte)((len >> 16) & 0xFF);
                    rgbValues[6] = (byte)((len >> 24) & 0xFF);
                    tcp.setData(rgbValues);
                }
            }
        }
    }
}
