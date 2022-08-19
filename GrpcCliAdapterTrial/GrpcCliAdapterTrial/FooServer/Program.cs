using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Grpc.Core;
using Foo.Core;

namespace FooServer
{
    class Program
    {
        public static int Port => 16880;

        static void Main( string[] args )
        {
            var server = new Server
            {
                Services = { Foo.FooService.BindService( new FooService() ) },
                Ports = { new ServerPort( "localhost", Port, ServerCredentials.Insecure ) }
            };
            server.Start();

            Console.WriteLine( $"FooService listening on port { Port }" );
            Console.WriteLine( "Press any key to stop server..." );
            Console.ReadLine();

            server.ShutdownAsync().Wait();
        }
    }
}
