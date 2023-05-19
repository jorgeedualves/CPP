/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:35:30 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/19 13:24:35 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Array.hpp"

int main(void)
{
    Array<char> a(10);
    Array<int> b(10);
    Array<float> c(10);
    Array<float> x(c);
    Array<std::string> d(5);
    Array<int> e(0);

    std::cout << "*** CHAR ***\n";
    for (size_t i = 0; i < 10; i++)
        a[i] = static_cast<char>(i + 'a');
    
    std::cout << a << "\n";

    std::cout << "*** INT ***\n";
    for (size_t i = 0; i< 10; i++)
        b[i] = static_cast<int>(i + 1);

    std::cout << b << "\n";
    
    std::cout << "*** FLOAT ***\n";    
    for (size_t i = 0; i < 10; i++)
        x[i] = static_cast<float>(1.1f + static_cast<float>(i));

    std::cout << x << "\n";

    std::cout << "*** STRING ***\n";
    for (size_t i = 0; i < 5; i++)
        d[i] = std::string("str") + static_cast<char> (i + '0' + 1);
    
    std::cout << d;

    std::cout << "\n";

    std::cout << "*** Out of Range index ***\n";
    try
    {
        e[100];
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what();
    }
    try
    {
        e[-1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
