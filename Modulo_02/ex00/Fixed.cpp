/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:30:41 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/11 17:23:15 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int const Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default Constructor Called" << std::endl;
	return;
}
    
Fixed::Fixed(Fixed const &src) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed &Fixed::operator=(Fixed const &src)
{
	std::cout << "Copy assignment operator calle" << std::endl;
	this->setRawBits(src.getRawBits());
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
	return;
} 