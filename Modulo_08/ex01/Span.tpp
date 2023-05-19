/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:52:10 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/19 14:52:36 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

template <typename T>
void Span::addRange(T itBegin, T itEnd)
{
    size_t maxCapacity = this->_maximum - this->_vect.size();
    if (std::distance(itBegin, itEnd) > static_cast<int>(maxCapacity))
    {
        throw NotEnoughCapacity();
    }
    while (itBegin != itEnd)
    {
        this->_vect.push_back(*itBegin);
        itBegin++;
    }
}
#endif