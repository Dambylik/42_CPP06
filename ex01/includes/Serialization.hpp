
#pragma once

#include "Colors.hpp"
#include <iostream>
#include <stdint.h>
#include <string>


struct Data {
	std::string str;
};

class Serialization {

    public:

        ~Serialization();
        Serialization( Serialization const & other );
        Serialization & operator=( Serialization const & other );

        static uintptr_t    serialize( Data* ptr );
        static Data*        deserialize( uintptr_t raw );

    private:

        Serialization();
	
};