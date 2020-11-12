// filereader.h
#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <streambuf>
#include <string>

class FileReader
{
public:
    static std::string readAll( const std::string fileName )
    {
        std::string contents("");
        std::ifstream ifs( fileName );
        if ( ifs.is_open() )
        {
            std::istreambuf_iterator<char> it( ifs );
            std::istreambuf_iterator<char> last;
            contents = std::string( it, last );
        }
        return contents;
    }
};

#endif // FILEREADER_H
