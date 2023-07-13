/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:04:12 by azamario          #+#    #+#             */
/*   Updated: 2023/07/13 13:13:39 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string ScalarConverter::_string = "";
std::string ScalarConverter::_nonStandartValue = "";

char        ScalarConverter::_char = 0;
int         ScalarConverter::_int = 0;
float       ScalarConverter::_float = 0;
double      ScalarConverter::_double = 0;
bool        ScalarConverter::_nan = false;


ScalarConverter::ScalarConverter(void)
{
    return;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
	return;
}

ScalarConverter::~ScalarConverter(void)
{
    return;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
	_string =	rhs._string;
	_char = 	rhs._char;
	_int =		rhs._int;
	_float =	rhs._float;
	_nan =		rhs._nan;
	
	return (*this);
}

void ScalarConverter::convert(const std::string &convertIt)
{
	_string =			convertIt;
	_nonStandartValue =	"";
	_nan =				false;
	_convert();
	_print();

	return;
}

void ScalarConverter::_convert(void)
{
	if (_string.size() == 1 && _string.find_first_not_of("0123456789") != std::string::npos)
		_convertToChar();
	else if (_string.find_first_not_of('f') != std::string::npos)
		_convertToFloat();
	else if (_string.find_first_not_of('.') != std::string::npos)
		_convertToDouble();
	else if (strtod(_string.c_str(), NULL) > INTMAX || strtod(_string.c_str(), NULL) < INTMIN)
		_convertToDouble();
	else
		_convertToInt();
}

void ScalarConverter::_convertToChar(void)
{
	_char =		static_cast<char>(_string[0]);
	_int =		static_cast<int>(_char);
	_float =	static_cast<float>(_char);
	_double =	static_cast<double>(_char);  
}

void ScalarConverter::_convertToInt(void)
{
	_int =		static_cast<int>(atoi(_string.c_str()));
	_char =		static_cast<char>(_int);
	_float =	static_cast<float>(_int);
	_double =	static_cast<double>(_int);
}

void ScalarConverter::_convertToFloat(void)
{

	_float =	static_cast<float>(atof(_string.c_str()));
	_char =		static_cast<char>(_float);
	_int =		static_cast<int>(_float);
	_double =	static_cast<double>(_float);
}

void ScalarConverter::_convertToDouble(void)
{
  	_double =	static_cast<double>(strtod(_string.c_str(), NULL));
	_char =		static_cast<char>(_double);
	_int =		static_cast<int>(_double);
	_float =	static_cast<float>(_double);
}

void ScalarConverter::_print(void)
{
	if (_isNonStandartValue() || _isNan() || _isString())
		_printNonStandartValue();
	else
		_printConvertedValue();
}

bool ScalarConverter::_isNonStandartValue(void)
{
	std::string nonStandartValues[6] = { "-inf", "+inf", "nan", "-inff", "+inff", "nanf" };
	int i = -1;

	while (++i < 6)
	{
		if (_string == nonStandartValues[i])
		{
			if (i > 2)
				_nonStandartValue = nonStandartValues[i - 3];
			else
				_nonStandartValue = nonStandartValues[i];
			return (true);
		}
	}
	return (false);
}

bool ScalarConverter::_isNan(void)
{
	if (_string != "nan")
    	return (false);
	_nan = true ;
	return (true);
}

bool ScalarConverter::_isString(void)
{
	if (_string.length() > 1 && _string.find_first_not_of("-+.f0123456789") != std::string::npos)
    	return (true);
  	return (false);
}

void ScalarConverter::_printNonStandartValue(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	
	if (_nan)
	{
    	std::cout << "float: nanf" << std::endl;
    	std::cout << "double: nan" << std::endl;
	}
	else if (_nonStandartValue != "")
	{
   		std::cout << "float: " << _nonStandartValue << "f" << std::endl;
    	std::cout << "double: " << _nonStandartValue << std::endl;		
	}
	else
	{
    	std::cout << "float: impossible" << std::endl;
    	std::cout << "double: impossible" << std::endl;		
	}
}

void ScalarConverter::_printConvertedValue(void)
{
	if (!_int || !isprint(_char))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << _char << "'" << std::endl;
	std::cout << "int: " << _int << std::endl;
	if (_float == _int)
  		std::cout << "float: " << _float << ".0f" << std::endl;
	else
  		std::cout << "float: " << _float << "f" << std::endl;
	if (_double == _int)
  		std::cout << "double: " << _double << ".0" << std::endl;
	else
  		std::cout << "double: " << _double << std::endl;
}
