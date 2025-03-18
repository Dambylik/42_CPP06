/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:26:19 by okapshai          #+#    #+#             */
/*   Updated: 2025/03/18 12:11:08 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Colors.hpp"

#include <iostream>
#include <cstdlib>
#include <exception>
#include <cstdlib> 

class Base {
    
    public:
        virtual ~Base();
};

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

Base*   aCreator();
Base*   bCreator();
Base*   cCreator();
