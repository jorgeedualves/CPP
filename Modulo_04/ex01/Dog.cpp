/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:04:03 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/26 12:16:50 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "Dog Default Constructor called\n";
    this->_brain = new Brain();
}

Dog::Dog(Dog const &src) : Animal("Dog")
{
    std::cout << "Dog Copy Constuctor called\n";
    this->_brain = new Brain (*src.getBrain());
    *this = src;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called\n";
    delete this->_brain;
}

Dog &Dog::operator=(Dog const &rhs)
{
    std::cout << "Dog Assingment Operator called\n";
    this->_type = rhs.getType();
    *this->_brain = *rhs.getBrain();
    return(*this);
}

Brain const *Dog::getBrain(void) const
{
    return(this->_brain);
}

void Dog::makeSound(void) const
{
    std::cout << "Aauuuuu 🐕\n";
}