/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:33:57 by okapshai          #+#    #+#             */
/*   Updated: 2025/03/18 12:39:33 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

// -------------------------------------------------------------------- Methods

Base* aCreator() { return (new A()); }

Base* bCreator() { return (new B()); }

Base* cCreator() { return (new C()); }

Base* generate(void) {
    
    Base*(*functions[3])() = {aCreator, bCreator, cCreator};
    return (functions[rand() % 3]());
}

void identify( Base* p ) {
    
    A* a = dynamic_cast<A*>(p);
    if (a != NULL) {
        std::cout << LGREEN << "Type: A" << RESET << std::endl;
    }
    else {
        B* b = dynamic_cast<B*>(p);
        if (b != NULL) {
            std::cout << LBLUE << "Type: B" << RESET << std::endl;
        }
        else {
            C* c = dynamic_cast<C*>(p);
            if (c != NULL) {
                std::cout << MAGENTA << "Type: C" << RESET << std::endl;
            }
            else {
                std::cout << "Type: Unknown" << std::endl;
            }
        }
    }
}

void identify( Base& p ) {
    
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << LGREEN "Type: A" << RESET << std::endl;
    } catch( const std::exception& e ) {
        try {
            B& b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << LBLUE << "Type: B" << RESET << std::endl;
        } catch( const std::exception& e ) {
            try {
                C& c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << MAGENTA << "Type: C" << RESET << std::endl;
            } catch( const std::exception& e ) {
                std::cout << "Type: Unknown" << std::endl;
            }
        }
    }
}