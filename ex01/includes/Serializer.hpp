/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:46:34 by okapshai          #+#    #+#             */
/*   Updated: 2025/03/17 12:46:37 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Colors.hpp"
#include <iostream>
#include <stdint.h>
#include <string>


struct Data {
	std::string name;
    int         value;
};

class Serializer {

    public:

        ~Serializer();
        Serializer( Serializer const & other );
        Serializer & operator=( Serializer const & other );

        static uintptr_t    serialize( Data* ptr );
        static Data*        deserialize( uintptr_t raw );

    private:

        Serializer();	
};