using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using adapter;

namespace FooAdapterApp
{
    class Program
    {
        static void Main( string[] args )
        {
            var foo = new FooAdapter();

            Console.WriteLine( "start..." );

            foo.Sleep( 3 );

            Console.WriteLine( "end." );
        }
    }
}
