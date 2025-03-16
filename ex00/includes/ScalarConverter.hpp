// Created on iPad.


#pragma once

#include "Colors.hpp"
#include <iostream>
#include <climits>
#include <cstdlib>
#include <string>


class ScalarConverter {

    public:

        ~ScalarConverter();

        ScalarConverter( ScalarConverter const & other );
        ScalarConverter &   operator=( ScalarConverter const & other );
        
        static void         convert( std::string & toConvert );

    private:

        ScalarConverter();
};