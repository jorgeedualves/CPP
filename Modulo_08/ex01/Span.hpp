/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:24:36 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 13:24:37 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <climits>
#include <exception>
#include <vector>
#include <iostream>


class Span
{
    public:
        class NotEnoughCapacity : public std::exception
        {
            public:
                const char* what(void) const throw();          
        };
        
        class InsufficientElements : public std::exception
        {
            public:
                const char* what(void) const throw();                     
        };

        Span(void);
        explicit Span(unsigned int maximum);
        Span(const Span& src);
        ~Span(void);

        Span& operator=(const Span& rhs);

        const std::vector<int>& getContainer(void) const;
        size_t getMaximum(void) const;
        size_t getSize(void) const;
        int getValueAt(size_t pos);

        void addNumber(int n);

        template <typename T>
        void addRange(T itBegin, T itEnd);

        size_t shortestSpan(void);
        size_t longestSpan(void);

		void printVector(void) const;
        
    private:
        std::vector<int> _vector;
        unsigned int _maximum;
};

#include "Span.tpp"

#endif
