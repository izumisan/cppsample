using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.IO;
using System.Diagnostics;
using NUnit.Framework;
using Grpc.Core;

namespace Foo.Core.Tests
{
    [TestFixture]
    public class FooServerTest
    {
        public FooServerTest()
        {
            string host = "localhost";
            int port = 168080;

            //@@@ Note:
            // FooServerをテストプログラムから起動すると、
            // クライアントからのリクエスト時に"Grpc.Core.RpcExecetionが発生してしまう"
            // おそらく、同一アプリでサーバー/クライアント同一ポートを占有しているためと思われる...
            //_server = new FooServer( host, port );

            Channel = new Channel( host, port, ChannelCredentials.Insecure );
            Client = new Foo.FooService.FooServiceClient( Channel );

            _server = new Process
            {
                StartInfo = new ProcessStartInfo(
                    Path.Combine(
                        TestContext.CurrentContext.TestDirectory,
                        "FooServer.exe" ) )
                    {
                        RedirectStandardInput = true,
                        UseShellExecute = false
                    }
            };
            _server.Start();
        }

        ~FooServerTest()
        {
            //var s = _server.ShutdownAsync();
            //var c = Channel.ShutdownAsync();
            //Task.WaitAll( new[] { s, c } );

            //@@@ Note:
            // FooServer.exeを起動する方法ではテスト自体は成功するが、
            // デバッガ実行してみると、Channel.ShutdownAsync()で例外が発生している.
            //
            // また、FooServerプログラムもkillしているので正常に終了できていない...
            // (これは、killではなくキー送信してしまえば解決できる気がする)
            //_server.Kill();
            _server.StandardInput.WriteLine( "q" );
            _server.WaitForExit();
            Channel.ShutdownAsync().Wait();
        }

        //private readonly FooServer _server = null;
        private Process _server = null;
        private Channel Channel { get; } = null;
        private Foo.FooService.FooServiceClient Client { get; } = null;

        [Test]
        //[Ignore( "Grpc.Core.RpcExecetionが発生してしまう" )]
        public void Sleepテスト()
        {
            var actual = Client.Sleep( new SleepRequest { Seconds = 1 } );
            Assert.That( actual.Reply, Is.EqualTo( 1 ) );
        }
    }
}
