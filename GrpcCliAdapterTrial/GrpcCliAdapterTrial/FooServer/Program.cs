using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//using Grpc.Core;

namespace FooServer
{
    using Foo.Core;

    class Program
    {
        public static int Port => 168080;

        static void Main( string[] args )
        {
            //var server = new Server
            //{
            //    Services = { Foo.FooService.BindService( new FooService() ) },
            //    Ports = { new ServerPort( "localhost", Port, ServerCredentials.Insecure ) }
            //};
            var server = new FooServer( "localhost", Port );
            server.Start();

            Console.WriteLine( $"FooService listening on port { Port }" );
            Console.WriteLine( "Press any key to stop server..." );
            Console.ReadLine();

            server.ShutdownAsync().Wait();
        }
    }
}
