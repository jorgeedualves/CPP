/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:28:58 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/09 23:08:35 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) : _input(""), _raw(0)
{
    std::cout << "Defaut Constructor Called\n";
    return;
}

ScalarConverter::ScalarConverter(const std::string& raw) : _input(raw), _raw(0)
{
    if (raw.length() == 1 && std::isalpha(*raw.begin()))
        this->_raw = static_cast<double>(*raw.begin());
    else
        this->_raw = std::strtod(raw.c_str(), NULL);
}

ScalarConverter::ScalarConverter(ScalarConverter& src)
{

}

ScalarConverter::~ScalarConverter(void)
{

}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{

}

ScalarConverter::operator char()
{

}
    
ScalarConverter::operator int()
{

}

ScalarConverter::operator float()
{

}

ScalarConverter::operator double()
{

}

std::string ScalarConverter::getInput(void) const
{

}

double ScalarConverter::getRaw(void) const
{

}