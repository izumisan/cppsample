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
        // テスト実行できない

        [Test]
        public void Basicテスト()
        {
            var foo = new FooService();
            var ret = foo.Sleep( new SleepRequest { Seconds = 3 }, null );
            Assert.That( ret, Is.EqualTo( 3 ) );
        }
    }
}
