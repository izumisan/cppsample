using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Grpc.Core;

namespace Foo.Core
{
    public class FooService : Foo.FooService.FooServiceBase
    {
        public override Task<SleepReply> Sleep( SleepRequest request, ServerCallContext context )
        {
            var foo = new adapter.FooAdapter();
            var ret = foo.Sleep( request.Seconds );
            return Task.FromResult( new SleepReply { Reply = ret } );
        }
    }
}
