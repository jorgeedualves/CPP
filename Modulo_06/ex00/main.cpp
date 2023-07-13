/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:11:10 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 13:11:23 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
  	{
    	std::cout << "\nUsage: ./ScalarConverter <stringToConvert>\n" << std::endl;
	    return (1);
  	}
  	std::cout << std::endl;

	ScalarConverter::convert(argv[1]);

  	std::cout << std::endl;
	return (0);
}
