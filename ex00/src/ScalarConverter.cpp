/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:13:46 by okapshai          #+#    #+#             */
/*   Updated: 2025/03/18 11:27:24 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter( ScalarConverter const & other ) { (*this) = other; }

ScalarConverter & ScalarConverter::operator=( ScalarConverter const & other ) {

    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

// -------------------------------------------------------------------- Methods

void	ScalarConverter::convert( std::string const & toConvert )
{
	std::string pseudo_literals[6] = {
		"-inff", "+inff", "nanf",
		"-inf", "+inf", "nan"
	};

	std::string toChar = "";
	long long	toInt = 0;
	float		toFloat = 0;
	double		toDouble = 0;
	
	if (toConvert.size() == 1 && std::isprint( toConvert[0]) && !std::isdigit(toConvert[0])) {
		toChar = toConvert[0];
		std::cout << "char: " << toChar << std::endl;
		std::cout << "int: " << static_cast<int>(toChar[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(toChar[0]) << ".0f" <<std::endl;
		std::cout << "double: " << static_cast<double>(toChar[0]) << ".0" <<std::endl;
		return ;
	}
	
	toInt = std::atoll(toConvert.c_str());
    
	if (toConvert[toConvert.length() - 1] == 'f') {
		toFloat = std::atof(toConvert.c_str());
		toDouble = static_cast<double>(toFloat);
	}
    else {
		toDouble = std::atof(toConvert.c_str());
		toFloat = static_cast<float>(toDouble);
	}

	for (int i = 0; i < 6; i++) {
		if (toConvert == pseudo_literals[i]) {
			toChar = "impossible";
			break ;
		}
	}
	
	if (toChar == "" && toInt < 256 && toInt >= 0) {
        if (std::isprint(toInt)) {
            toChar = "'";
            toChar += static_cast<char>(toInt);
            toChar += "'";            
        }
        else {
            toChar = "Non displayable";
        }
	}
    else if (toChar == "") {
		toChar = "Non printable";
	}
	
    std::cout << "char: " << toChar << std::endl;

    if (toChar == "impossible" || (toInt < INT_MIN || toInt > INT_MAX))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << toInt << std::endl;
    
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