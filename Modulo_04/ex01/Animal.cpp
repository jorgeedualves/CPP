/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:11:28 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/25 12:53:16 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal default Constructor called\n";
}

Animal::Animal(std::string const type) : _type(type)
{
	std::cout << "Animal Parametric Constructor called\n";
}

Animal::Animal(Animal const &src)
{
	std::cout << "Animal Copy Constructor called\n";
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called\n";
}

Animal &Animal::operator=(Animal const &rhs)
{
	std::cout << "Animal assignment operator called\n";
	this->_type = rhs.getType();
	return (*this);
}

std::string const Animal::getType(void) const
{
	return(this->_type);
}

void Animal::setType(std::string const type)
{
	this->_type = type;
}
void Animal::makeSound(void) const
{
	std::cout << "🐾\n";
}

std::ostream &operator <<(std::ostream &out, Animal const &in)
{
	out << in.getType();
	return (out);
}