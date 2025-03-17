/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:47:09 by okapshai          #+#    #+#             */
/*   Updated: 2025/03/17 14:02:24 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#include <iostream>
#include "Serializer.hpp"

int main() {

    Data myData;
    myData.name = "Olaf";
    myData.value = 42;

    Data* originalPtr = &myData;

    std::cout << "Original Data Name: " << MAGENTA << originalPtr->name << RESET << std::endl;
    std::cout << "Original Data Value: " << MAGENTA << originalPtr->value << RESET << std::endl;
    std::cout << "Original pointer: " << LGREEN << originalPtr << RESET << std::endl;

    uintptr_t raw = Serializer::serialize(originalPtr);
    std::cout << "Serialized uintptr_t: " << ORANGE << raw << RESET << std::endl;

    Data* newPtr = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << LGREEN << newPtr << RESET << std::endl;

    std::cout << "Deserialized Data Name: " << MAGENTA << newPtr->name << RESET << std::endl;
    std::cout << "Deserialized Data Value: " << MAGENTA << newPtr->value << RESET << std::endl;

    return 0;
}
