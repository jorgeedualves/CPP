/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:59:13 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/18 19:15:47 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char* Span::NotEnoughCapacity::what(void) const throw()
{
    return ("No enough Capacity");
}

const char* Span::InsufficientElements::what(void) const throw()
{
    return ("Insufficient Elements");
}

Span::Span(void) :_vect(std::vector<int>()), _maximum(0)
{
    return;
}

Span::Span(size_t _maximum) : _vect(std::vector<int>()), _maximum(_maximum)
{
    return;
}
