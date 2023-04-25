/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:02:43 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/25 13:00:22 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
    std::cout << "WrongAnimal Default Constructor\n";
}

WrongAnimal::WrongAnimal(std::string const type) : _type(type)
{
    std::cout << "WrongAnimal Parametric called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
    std::cout << "WrongAnimal Copy Constructor called\n";
    *this = src;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal Destructor called\n";
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
    std::cout << "WrongAnimal assigment operator called\n";
    this->_type = rhs.getType();
    return(*this);

}

std::string const WrongAnimal::getType(void) const
{
    return (this->_type);
}

void WrongAnimal::setType(std::string const type)
{
    this->_type = type;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal 👾\n";
}

std::ostream &operator<<(std::ostream &out, WrongAnimal const &in)
{
    out << in.getType();
    return(out);
}