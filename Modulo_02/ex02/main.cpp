/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:56:27 by joeduard          #+#    #+#             */
/*   Updated: 2023/06/05 21:26:17 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
    Fixed a; //Default Constructor called
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );       // Float construct(float construct * int construct)
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << "\na: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    if (a < b)
        std::cout << "a < b\n";
    if (a <= b)
        std::cout << "a <= b\n";
    if (a != b)
        std::cout << "a != b\n";

    std::cout << "\n";

    std::cout << "a + b:  " << a + b << std::endl;
    std::cout << "a - b:  " << a - b << std::endl;
    std::cout << "a * b:  " << a * b << std::endl;
    std::cout << "a / b:  " << a / b << std::endl;
    return 0;
}