using System;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ScreenShotSender
{
    public class TCPSender
    {
        private Task _task;
        private string _addr;
        private int _port;
        private byte[] _sendBuffer;
        private CancellationTokenSource _cts;

        public TCPSender()
        {
        }

        public void start(string addr, int port)
        {
            _addr = addr;
            _port = port;
            _cts = new CancellationTokenSource();
            _task = Task.Run(() => { TaskClient(_cts.Token); });
        }

        public void stop()
        {
            _cts?.Cancel();
        }


        public void setData(byte[] src)
        {
//            _sendBuffer = src;
            Interlocked.Exchange(ref _sendBuffer, src);
        }

        private void TaskClient(CancellationToken ct)
        {
            byte[] resBytes = new byte[256];
            while (!ct.IsCancellationRequested)
            {
                try
                {
                    var client = new TcpClient(_addr, _port);
                    var ns = client.GetStream();
                    client.NoDelay = true;
                    ns.ReadTimeout = 2000;
                    ns.WriteTimeout = 2000;
                    var nodatacount = 0;
                    while (!ct.IsCancellationRequested && client.Connected)
                    {
                        try
                        {
                            var res = ns.Read(resBytes, 0, resBytes.Length);
                            if (0 < res)
                            {
                                nodatacount = 0;
                                if (resBytes[0] == 0x4A  // "JPG"
                                 && resBytes[1] == 0x50
                                 && resBytes[2] == 0x47
                                 && resBytes[3] == 0x0A) {
//                                    byte[] tmp = _sendBuffer;
                                    byte[] tmp = null;
                                    do {
                                        tmp = Interlocked.Exchange(ref _sendBuffer, null);
                                    } while (null == tmp);
                                    //*/
                                    ns.Write(tmp, 0, tmp.Length);
                                }
                                else
                                {
                                    Console.WriteLine("unknown cmd");
                                }
                            }
                            else
                            {
                                Thread.Sleep(1);
                                if (++nodatacount > 1000) break;
                            }
                        }
                        catch (Exception ex)
                        {
                            //Console.WriteLine(ex.Message);
                            break;
                        }
                    }
                    ns.Close();
                    client.Close();
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.Message);
                }
            }
        }
    }
}