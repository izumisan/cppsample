using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Foo.Core
{
    public class FooServer : Grpc.Core.Server
    {
        public FooServer( string host, int port )
            : base()
        {
            Services.Add( Foo.FooService.BindService( new FooService() ) );
            Ports.Add( new Grpc.Core.ServerPort( host, port, Grpc.Core.ServerCredentials.Insecure ) );
        }
    }
}
