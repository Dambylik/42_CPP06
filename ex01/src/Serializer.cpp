/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:44:13 by okapshai          #+#    #+#             */
/*   Updated: 2025/03/17 13:46:57 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"

Serializer::Serializer() {

    //std::cout << GREEN << "Serializer default constructor called" << RESET << std::endl;
}

Serializer::Serializer( Serializer const & other ) {

    //std::cout << GREEN << "Serializer copy constructor called" << RESET << std::endl;
	(*this) = other;
}

Serializer::~Serializer() {

    //std::cout << GREEN << "Serializer destructor called" << RESET << std::endl;
}

Serializer & Serializer::operator=( Serializer const & other ) {

    //std::cout << GREEN << "Serializer assignment operator called" << RESET << std::endl;

    (void)other;
    return (*this);
}

// -------------------------------------------------------------------- Methods

uintptr_t Serializer::serialize( Data* ptr ) { return ( reinterpret_cast<uintptr_t>(ptr) ); }
Data* Serializer::deserialize( uintptr_t raw ) { return ( reinterpret_cast<Data *>(raw) ); }