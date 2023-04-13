/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:03:20 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/13 16:11:52 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief quatro objetos Fixed da classe Fixed e os inicializa com diferentes valores.
 * A classe Fixed é uma classe definida pelo usuário que provavelmente representa um número de ponto fixo.
 * Os objetos são inicializados de diferentes maneiras:

    a é criado usando um construtor padrão sem argumentos, e depois é atribuído o valor de 1234.4321f.
    b é criado usando um construtor que recebe um argumento inteiro 10.
    c é criado usando um construtor que recebe um argumento 42.42f.
    d é criado usando um construtor de cópia que recebe o objeto b.
 * 
 * @return int 
 */
int main( void )
{

    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}