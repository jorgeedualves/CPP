/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:23:23 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 13:23:30 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main(void)
{
	Array<int> in(10);
  	Array<char> ch(10);
  	Array<float> fl(10);
  	Array<std::string> st(5);
  	Array<int> out(0);
	std::cout << "\n";

  	std::cout << "[ INT ARRAY ]\n";
  	for (size_t i = 0; i < 10; i++)
	{
    	in[i] = static_cast<int>(i + 1);
  	}
  	std::cout << in;
	std::cout << "\n";

  	std::cout << "[ CHAR ARRAY ]\n";
  	for (size_t i = 0; i < 10; i++)
	{
    	ch[i] = static_cast<char>(i + 'a');
  	}
  	std::cout << ch;
	std::cout << "\n";

  	std::cout << "[ FLOAT ARRAY ]\n";
  	for (size_t i = 0; i < 10; i++)
	{
    	fl[i] = static_cast<float>(1.1f + static_cast<float>(i));
  	}
  	std::cout << fl;
  	std::cout << "\n";

  	std::cout << "[ STRING ARRAY ]\n";
  	for (size_t i = 0; i < 5; i++)
	{
    	st[i] = std::string("str") + static_cast<char>(i + '0' + 1);
  	}
  	std::cout << st;
  	std::cout << "\n";

  	std::cout << "[ Out of Range INDEX ]\n";
  	try
	{
    	out[100];
  	}
	catch (const std::exception& e)
	{
    	std::cerr << e.what();
 	}
  	try
	{
    	out[-1];
  	}
	catch (const std::exception& e)
	{
    	std::cerr << e.what();
  	}
	std::cout << "\n";

  	return (0);
}
