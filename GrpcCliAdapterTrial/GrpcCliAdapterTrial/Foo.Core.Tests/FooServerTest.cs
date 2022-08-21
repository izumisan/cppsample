using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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

            _server = new FooServer( host, port );

            Channel = new Channel( host, port, ChannelCredentials.Insecure );
            Client = new Foo.FooService.FooServiceClient( Channel );

            _server.Start();
        }

        ~FooServerTest()
        {
            var s = _server.ShutdownAsync();
            var c = Channel.ShutdownAsync();
            Task.WaitAll( new[] { s, c } );
        }

        private readonly FooServer _server = null;
        private Channel Channel { get; } = null;
        private Foo.FooService.FooServiceClient Client { get; } = null;

        [Test]
        [Ignore( "Grpc.Core.RpcExecetionが発生してしまう" )]
        public void Sleepテスト()
        {
            //@@@ Note:
            // おそらく、同一アプリでサーバー/クライアント同一ポートを占有しているためと思われる...

            var actual = Client.Sleep( new SleepRequest { Seconds = 1 } );
            Assert.That( actual.Reply, Is.EqualTo( 1 ) );
        }
    }
}
