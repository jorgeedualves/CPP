/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:04:03 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/25 13:01:02 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "Dog Default Constructor called\n";
}

Dog::Dog(Dog const &src) : Animal("Dog")
{
    std::cout << "Dog Copy Constuctor called\n";
    *this = src;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called\n";
}

Dog &Dog::operator=(Dog const &rhs)
{
    std::cout << "Dog Assingment Operator called\n";
    this->_type = rhs.getType();
    return(*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Aauuuuu 🐕\n";
}