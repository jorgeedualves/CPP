/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:18:41 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/25 12:59:15 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat Default Constructor called\n";
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat Copy Constructor called\n";
    *this = src;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called\n";
}

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
    std::cout << "WrongCat Assigment Operator called\n";
    this->_type = rhs.getType();
    return(*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "WrongCat ❌\n";
}