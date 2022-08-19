using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Grpc.Core;

namespace FooClient
{
    class Program
    {
        public static int Port => 16880;

        static void Main( string[] args )
        {
            Channel channel = new Channel( "localhost", Port, ChannelCredentials.Insecure );

            var client = new Foo.FooService.FooServiceClient( channel );

            var input = string.Empty;
            while ( string.Compare( input, "q", true ) != 0 )
            {
                Console.WriteLine( "Press any key (quit: q)" );

                input = Console.ReadKey( true ).KeyChar.ToString();

                int seconds = 0;
                int.TryParse( input, out seconds );

                Console.WriteLine( $"req: { seconds }" );

                var req = new Foo.SleepRequest { Seconds = seconds };
                var reply = client.Sleep( req );

                Console.WriteLine( $"reply: { reply.Reply }" );
            }

            channel.ShutdownAsync().Wait();
        }
    }
}
