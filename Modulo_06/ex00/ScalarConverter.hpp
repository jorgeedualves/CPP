/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:58:51 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/09 21:41:31 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTE_HPP
#define SCALARCONVERTE_HPP

#include <cstdlib>
#include <sstream>
#include <string>
#include <iostream>

class ScalarConverter
{
    public:
        ScalarConverter(void);
        explicit ScalarConverter(const std::string&);
        ScalarConverter(ScalarConverter&);
        ~ScalarConverter(void);

        ScalarConverter& operator=(const ScalarConverter& rhs);

        operator char();
        operator int();
        operator float();
        operator double();

        std::string getInput(void) const;
        double getRaw(void) const;

    private:
        const std::string _input;
        double _raw;

};

#endif