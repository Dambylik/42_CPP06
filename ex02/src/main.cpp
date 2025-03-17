/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:47:09 by okapshai          #+#    #+#             */
/*   Updated: 2025/03/17 14:53:58 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


int main() {

    srand(time(NULL));
    for (int i = 0; i < 10; ++i) { 
        std::cout << "Test " << i + 1 << ":" << std::endl;

        Base* obj = generate();

        std::cout << "Using pointer: ";
        identify(obj);

        std::cout << "Using reference: ";
        identify(*obj);

        delete obj;

        std::cout << "---------------------" << std::endl;
    }
    return 0;
}