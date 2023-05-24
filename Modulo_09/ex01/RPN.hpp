/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:54:09 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/24 12:00:17 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <stack>

class ReversePolishNotation
{
    public:
        ReversePolishNotation(void);
        ReversePolishNotation(const ReversePolishNotation& src);
        ~ReversePolishNotation(void);

        ReversePolishNotation &operator=(const ReversePolishNotation& rhs);

        double evaluate(std::string expression);

        class Error : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif