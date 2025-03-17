/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:33:57 by okapshai          #+#    #+#             */
/*   Updated: 2025/03/17 14:54:34 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
    
    //std::cout << GREEN << "Base destructor called" << RESET << std::endl;
}

// -------------------------------------------------------------------- Methods

Base* aCreator() {
    //std::cout << LGREEN << "A created" << RESET << std::endl;
    return (new A());
}

Base* bCreator() {
    //std::cout << LBLUE << "B created" << RESET << std::endl;
    return (new B());
}

Base* cCreator() {
    //std::cout << YELLOW << "C created" << RESET << std::endl;
    return (new C());
}

Base* generate(void) {
    Base*(*functions[3])() = {aCreator, bCreator, cCreator};
    return (functions[rand() % 3]());
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << LGREEN << "Type: A" << RESET << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << LBLUE << "Type: B" << RESET << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << MAGENTA << "Type: C" << RESET << std::endl;
    else
        std::cout << "Type: Unknown" << std::endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << LGREEN "Type: A" << RESET << std::endl;
    } catch(const std::exception& e) {
        try {
            B& b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << LBLUE << "Type: B" << RESET << std::endl;
        } catch(const std::exception& e) {
            try {
                C& c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << MAGENTA << "Type: C" << RESET << std::endl;
            } catch(const std::exception& e) {
                std::cout << "Type: Unknown" << std::endl;
            }
        }
    }
}