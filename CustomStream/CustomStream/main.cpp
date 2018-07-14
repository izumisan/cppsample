#include "customstream.h"

int main()
{
    auto&& cs = izm::CustomStream();

    cs << "Hello World" << izm::endl;
    cs << "Hello World" << izm::endl;
    cs << 1 << izm::endl 
       << 1.0 << izm::endl 
       << 1.23 << izm::endl
       << 0.1234567890 << izm::endl;

    cs << izm::timestamp << izm::endl;
    cs << izm::printf( "Hello World %d %f", 1, 1.2 ) << izm::endl;

    cs << izm::callerInfo( __FILE__, __LINE__, __func__ ) << izm::endl;
    cs << CALLERINFO << izm::endl;

    cs << izm::callerInfo( __FILE__, __LINE__, __func__, false ) << izm::endl;
    cs << CALLERINFO_L << izm::endl;

    cs.setOnceEvery( 10 );
    for ( int i = 0; i < 100; ++i )
    {
        cs << i << izm::endl;
    }

    cs << izm::once( 5 ) << "once(5)" << izm::endl;
    for ( int i = 0; i < 50; ++i )
    {
        cs << i << izm::endl;
    }

    return 0;
}
