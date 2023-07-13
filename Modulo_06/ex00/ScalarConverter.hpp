/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:57:42 by azamario          #+#    #+#             */
/*   Updated: 2023/07/13 13:14:46 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <string>

# define INTMAX 2147483647
# define INTMIN -2147483648

class ScalarConverter
{
	public:
		~ScalarConverter(void);
		ScalarConverter		&operator=(const ScalarConverter &hrs);
		static void			convert(const std::string &convertIt);
		
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &src);
		
		static void			_convert(void);

		static void			_print(void);
		static void			_printConvertedValue(void);
		static void			_printNonStandartValue(void);

		static bool			_isNan(void);
		static bool			_isString(void);
		static bool			_isNonStandartValue(void);

		static void			_convertToChar(void);
		static void			_convertToInt(void);
		static void			_convertToFloat(void);
		static void			_convertToDouble(void);

		static std::string 	_string;
		static std::string 	_nonStandartValue;
		static char 		_char;
		static int			_int;
		static float		_float;
		static double		_double;
		static bool			_nan;	
};

#endif
