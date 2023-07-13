/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:26:00 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 13:26:02 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

ReversePolishNotation::ReversePolishNotation(void)
{
    return;
}

ReversePolishNotation::ReversePolishNotation(const ReversePolishNotation &src)
{
    *this = src;
}

ReversePolishNotation::~ReversePolishNotation(void)
{
    return;
}

ReversePolishNotation &ReversePolishNotation::operator=(const ReversePolishNotation &rhs)
{
    if (this != &rhs)
        *this = rhs;
    return (*this);
}

double ReversePolishNotation::evaluate(std::string expression)
{
    std::stack<double>operandStack;
    std::string token(expression);

    int i = -1;

    while (token[++i])
    {	
        if (token[i] == ' ')
            continue;
        else if (isdigit(token[i]))
            operandStack.push(token[i] - '0');
        else if (token[i] == '+' || token[i] == '-' || token[i] == '*' || token[i] == '/')
        {
            if (operandStack.size() < 2)
                throw std::runtime_error("\nError: not enough operands\n");
            double rhs = operandStack.top();
            operandStack.pop();
            double lhs = operandStack.top();
            operandStack.pop();
            if (token[i] == '+')
                operandStack.push(lhs + rhs);
            else if (token[i] == '-')
                operandStack.push(lhs - rhs);
            else if (token[i] == '*')
                operandStack.push(lhs * rhs);
            else if (token[i] == '/')
                operandStack.push(lhs / rhs);            
        }
        else
            throw std::runtime_error("\nError: invalid character\n");        
    }
    return (operandStack.top());  
}

const char* ReversePolishNotation::Error::what() const throw()
{
    return ("Error");
}
