/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:25:47 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 13:25:48 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./RPN <RPN expression>" << std::endl;
        return (1);
    }

    ReversePolishNotation calculator;

    std::string expression = argv[1];

    try
	{
        double result = calculator.evaluate(expression);
        std::cout << "\nResult: " << result << std::endl << std::endl;
    }
    catch (std::exception &excep)
    {
        std::cerr << excep.what() << std::endl;
    }
    return (0);
}
