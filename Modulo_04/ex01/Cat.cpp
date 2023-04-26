/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:56:44 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/26 11:52:42 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "Cat Default Constructor called\n";
    this->_brain = new Brain();
}

Cat::Cat(Cat const &src) : Animal("Cat")
{
    std::cout << "Cat Copy Constructor called\n";
    this->_brain = new Brain(*src.getBrain());
	*this = src;
}
Cat::~Cat(void)
{
    std::cout << "Cat Destructor called\n";
    delete this->_brain;
}

Cat &Cat::operator=(Cat const &rhs)
{
    std::cout << "Cat Assingment Operator called\n";
    this->_type = rhs.getType();
    *this->_brain = *rhs.getBrain();
    return (*this);
}

Brain const *Cat::getBrain(void) const
{
    return (this->_brain);
}

void Cat::makeSound(void) const
{
    std::cout <<"Meauuu 🐈\n";
}