/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:26:08 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 13:26:09 by joeduard         ###   ########.fr       */
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
        ReversePolishNotation(const ReversePolishNotation &src);
        ~ReversePolishNotation(void);
    
        ReversePolishNotation &operator=(const ReversePolishNotation &rhs);
    
        double evaluate(std::string expression);
    
        class Error : public std::exception
        {
            public:
                virtual const char* what() const throw();
        }; 
};

#endif