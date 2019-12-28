#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H

#include <string>

class FizzBuzz
{
public:
    FizzBuzz() = default;
    virtual ~FizzBuzz() = default;

public:
    static std::string fizzBuzz( const int& value )
    {
        auto ret = std::to_string( value );
        if ( value % 15 == 0 )
        {
            ret = "FizzBuzz";
        }
        else if ( value % 5 == 0 )
        {
            ret = "Buzz";
        }
        else if ( value % 3 == 0 )
        {
            ret = "Fizz";
        }
        else
        {
            // nothing.
        }
        return ret;
    }
};

#endif // FIZZBUZZ_H
