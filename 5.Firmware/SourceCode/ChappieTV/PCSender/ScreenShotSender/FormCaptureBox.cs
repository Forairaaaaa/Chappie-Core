using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ScreenShotSender
{
    public partial class FormCaptureBox : Form
    {
        public FormCaptureBox()
        {
            InitializeComponent();
        }

        private void FormCaptureBox_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (e.CloseReason == CloseReason.UserClosing)
            {
                Hide();
                e.Cancel = true;
            }
        }

        private Bitmap _bmp;
        private Point _mousePos;
        private Point _upperLeftDestination = new Point(0, 0);

        protected override bool ShowWithoutActivation => true;
        protected override CreateParams CreateParams
        {
            get {
                const int WS_BORDER = 0x00800000;
                CreateParams cp = base.CreateParams;
                cp.Style &= (~WS_BORDER);
                return cp;
            }
        }

        [DllImport("user32.dll", SetLastError = true)]
        [return: MarshalAs(UnmanagedType.Bool)]
        private static extern bool SetWindowPos(IntPtr hWnd, int hWndInsertAfter, int x, int y, int cx, int cy, uint uFlags);
        private void SetTopMost()
        {
            const int HWND_TOPMOST = -1;
            const uint SWP_NOSIZE = 0x0001;
            const uint SWP_NOMOVE = 0x0002;
            const uint SWP_NOACTIVATE = 0x0010;
            const uint SWP_SHOWWINDOW = 0x0040;
            const uint SWP_NOSENDCHANGING = 0x0400;
            SetWindowPos(this.Handle, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSENDCHANGING | SWP_NOSIZE | SWP_SHOWWINDOW);
        }
        private void FormCaptureBox_Load(object sender, EventArgs e)
        {
            SetTopMost();
            updateRegion();
        }
        private void FormCaptureBox_Resize(object sender, EventArgs e)
        {
            updateRegion();
            lblSize.Text = Width.ToString() + ":" + Height.ToString();
        }
        private void updateRegion()
        {
            var path = new System.Drawing.Drawing2D.GraphicsPath();
            path.AddRectangle(new Rectangle(0, 0, Width, Height));
            path.AddRectangle(new Rectangle(30,30, Width-60,Height-60));
            Region = new Region(path);
        }

        private void Form_MouseDown(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            if ((e.Button & MouseButtons.Left) == MouseButtons.Left) _mousePos = new Point(e.X, e.Y);
        }

        private void Form_MouseMove(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            if ((e.Button & MouseButtons.Left) == MouseButtons.Left)
            {
                Left += e.X - _mousePos.X;
                Top += e.Y - _mousePos.Y;
            }
        }

        public Bitmap CaptureFrame()
        {
            if (_bmp == null || _bmp.Size != Size)
            {
                _bmp = new Bitmap(Width, Height, PixelFormat.Format32bppArgb);
            }
            var g = Graphics.FromImage(_bmp);
            var upperLeftSource = this.Location;
            g.CopyFromScreen( upperLeftSource
                            , _upperLeftDestination
                            , this.Size
                            , CopyPixelOperation.SourceCopy
                            );
            Cursor.DrawStretched(g, new Rectangle(Control.MousePosition.X - Left , Control.MousePosition.Y - Top, Cursor.Size.Width, Cursor.Size.Height));
            return _bmp;
        }

        private void FormCaptureBox_KeyDown(object sender, KeyEventArgs e)
        {
            int p = e.Control ? 10 : 1;
            if (e.Shift)
            {
                var tmp = Size;
                switch (e.KeyCode)
                {
                    case Keys.Up:    tmp.Height -= p; break;
                    case Keys.Down:  tmp.Height += p; break;
                    case Keys.Left:  tmp.Width  -= p; break;
                    case Keys.Right: tmp.Width  += p; break;
                }
                Size = tmp;
            }
            else
            {
                var tmp = Location;
                switch (e.KeyCode)
                {
                    case Keys.Up:    tmp.Y -= p; break;
                    case Keys.Down:  tmp.Y += p; break;
                    case Keys.Left:  tmp.X -= p; break;
                    case Keys.Right: tmp.X += p; break;
                }
                Location = tmp;
            }
        }
    }
}
