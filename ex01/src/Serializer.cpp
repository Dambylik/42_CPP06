/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:44:13 by okapshai          #+#    #+#             */
/*   Updated: 2025/03/18 11:42:53 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer( Serializer const & other ) {(*this) = other;
}

Serializer::~Serializer() {}

Serializer & Serializer::operator=( Serializer const & other ) {

    (void)other;
    return (*this);
}

// -------------------------------------------------------------------- Methods

uintptr_t Serializer::serialize( Data* ptr ) { return ( reinterpret_cast<uintptr_t>(ptr) ); }
Data* Serializer::deserialize( uintptr_t raw ) { return ( reinterpret_cast<Data *>(raw) ); }