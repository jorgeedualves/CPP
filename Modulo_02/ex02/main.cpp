/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:56:27 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/18 10:58:49 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
    Fixed a; //Default Constructor called
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );       // Float construct(float construct * int construct)
    std::cout <<"1° Cout de a: \n" << a << std::endl;
    std::cout <<"1° Cout de a++: \n" << a++ << std::endl;
    std::cout <<"2° Cout de a: \n"<< a << std::endl;
    std::cout <<"1° Cout de ++a: \n" << ++a << std::endl;
    std::cout <<"3° Cout de a: \n" << a << std::endl;
    std::cout <<"1° Cout de b: \n" << b << std::endl;
    std::cout <<"1° Cout de max: \n" << Fixed::max( a, b ) << std::endl;
    return 0;
}