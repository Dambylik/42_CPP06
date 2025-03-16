// Created on iPad.

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {

    std::cout << GREEN << "ScalarConverter default constructor called" << RESET<< std::endl;
}

ScalarConverter::ScalarConverter( ScalarConverter const & other ) {

    std::cout << GREEN << "ScalarConverter copy constructor called" << RESET<< std::endl;
	(*this) = other;
}

ScalarConverter & ScalarConverter::operator=( ScalarConverter const & other ) {

    std::cout << GREEN << "ScalarConverter assignment operator called" << RESET<< std::endl;

    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter() {

    std::cout << GREEN << "ScalarConverter destructor called" << RESET << std::endl;
}

// -------------------------------------------------------------------- Methods

void	ScalarConverter::convert( std::string & toConvert )
{
	std::string pseudo_literals[6] = {
		"-inff", "+inff", "nanf",
		"-inf", "+inf", "nan"
	};

	// 4 variable types to handle
	std::string toChar = "";
	long long	toInt = 0;
	float		toFloat = 0;
	double		toDouble = 0;
	
	if (str.size() == 1 && std::isprint( str[0]) && !std::isdigit(str[0])) {
		toChar = str[0];
		std::cout << "char: " << toChar << std::endl;
		std::cout << "int: " << static_cast<int>(toChar[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(toChar[0]) << ".0f" <<std::endl;
		std::cout << "double: " << static_cast<double>(toChar[0]) << ".0" <<std::endl;
		return ;
	}
	
	toInt = std::atoll(str.c_str());
    
    // verify if float or double
	if (str[str.length() - 1] == 'f') {
		toFloat = std::atof(str.c_str());
		toDouble = static_cast<double>(toFloat);
	}
    else {
		toDouble = std::atof(str.c_str());
		toFloat = static_cast<float>(toDouble);
	}

	for (int i = 0; i < 6; i++) {
		if (str == pseudo_literals[i]) {
			toChar = "impossible";
			break ;
		}
	}
	
    // check range of char to int
	if (toChar == "" && toInt < 256 && toInt >= 0) {
        //check if char is printable
        if (std::isprint(toInt)) {
            toChar = "'";
            toChar += static_cast<char>(toInt);
            toChar += "'";            
        }
	}
    else if (toChar == "") {
		toChar = "Non printable";
	}
	
    // print char
    std::cout << "char: " << toChar << std::endl;

    // print int
    if (toChar == "impossible" || (toInt < INT_MIN || toInt > INT_MAX))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << toInt << std::endl;
    
    // print float && double 
    if (toChar == "impossible" && toFloat == 0) {
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
    else {
        if (toChar != "impossible" && toFloat - static_cast<int>(toFloat) == 0) {
            std::cout << "float: " << toFloat << ".0f" << std::endl;
            std::cout << "double: " << toDouble << ".0" << std::endl;
        }
        else {
            std::cout << "float: " << toFloat << "f" << std::endl;
            std::cout << "double: " << toDouble << std::endl;
        }
    }
}