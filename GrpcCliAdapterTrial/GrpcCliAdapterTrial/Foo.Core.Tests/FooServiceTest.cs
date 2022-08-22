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
    public class FooServiceTest
    {
        [Test]
        [Ignore( "このテストは実行できない" )]
        public void Basicテスト()
        {
            var foo = new FooService();
            var req = new SleepRequest { Seconds = 3 };
            // ここで無理やりSleep()を呼ぶため、第2引数にnullを入れているのは流石にダメっぽい
            var ret = foo.Sleep( req, null );
            Assert.That( ret, Is.EqualTo( 3 ) );
        }
    }
}
