#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream ifs( "foo.txt" );
    if ( ifs.is_open() )
    {
        std::cout << "foo.txt exist." << std::endl;
        std::string contents;
        std::getline( ifs, contents );
        std::cout << contents << std::endl;
    }
    else
    {
        std::cout << "foo.txt not found." << std::endl;
    }
    return 0;
}
