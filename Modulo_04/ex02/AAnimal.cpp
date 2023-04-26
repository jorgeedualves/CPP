/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:07:09 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/26 18:25:33 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("AAnimal")
{
	std::cout << "AAnimal default Constructor called\n";
}

AAnimal::AAnimal(std::string const type) : _type(type)
{
	std::cout << "AAnimal Parametric Constructor called\n";
}

AAnimal::AAnimal(AAnimal const &src)
{
	std::cout << "AAnimal Copy Constructor called\n";
	*this = src;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor called\n";
}

AAnimal &AAnimal::operator=(AAnimal const &rhs)
{
	std::cout << "AAnimal assignment operator called\n";
	this->_type = rhs.getType();
	return (*this);
}

std::string const AAnimal::getType(void) const
{
	return(this->_type);
}

void AAnimal::setType(std::string const type)
{
	this->_type = type;
}

std::ostream &operator <<(std::ostream &out, AAnimal const &in)
{
	out << in.getType();
	return (out);
}