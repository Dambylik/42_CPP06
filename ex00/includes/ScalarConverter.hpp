/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:12:13 by okapshai          #+#    #+#             */
/*   Updated: 2025/03/17 12:19:10 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        
        static void         convert( std::string const & toConvert );

    private:

        ScalarConverter();
};