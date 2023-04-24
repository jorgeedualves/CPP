/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:56:44 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/24 18:16:32 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "Cat Default Constructor called\n";
}

Cat::Cat(Cat const &src) : Animal("Cat")
{
    std::cout << "Cat Copy Constructor called\n";
	*this = src;
}
Cat::~Cat(void)
{
    std::cout << "Cat Destructor called\n";
}

Cat &Cat::operator=(Cat const &rhs)
{
    std::cout << "Cat Assingment Operator called\n";
    this->_type = rhs.getType();
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout <<"MEAUUUU\n";
}