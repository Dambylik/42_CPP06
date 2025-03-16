# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Olly <Olly@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 17:02:11 by okapshai          #+#    #+#              #
#    Updated: 2024/12/30 10:01:03 by Olly             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#include "Serialization.hpp"

Serialization::Serialization() {

    std::cout << GREEN << "Serialization default constructor called" << RESET << std::endl;
}

Serialization::Serialization( Serialization const & other ) {

    std::cout << GREEN << "Serialization copy constructor called" << RESET << std::endl;
	(*this) = other;
}

Serialization::~Serialization() {

    std::cout << GREEN << "Serialization destructor called" << RESET << std::endl;
}

Serialization & Serialization::operator=( Serialization const & other ) {

    std::cout << GREEN << "Serialization assignment operator called" << RESET << std::endl;

    (void)rhs;
    return (*this);
}

// -------------------------------------------------------------------- Methods

uintptr_t Serialization::serialize( Data* ptr ) { return ( reinterpret_cast<uintptr_t>(ptr) ); }
Data* Serialization::deserialize( uintptr_t raw ) { return ( reinterpret_cast<Data*>(raw) ); }