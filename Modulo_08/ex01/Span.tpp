/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:24:44 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 13:24:46 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

template <typename T>
void Span::addRange(T itBegin, T itEnd)
{
    size_t maxCapacity = this->_maximum - this->_vector.size();
    if(std::distance(itBegin, itEnd) > static_cast<int>(maxCapacity))
    {
        throw NotEnoughCapacity();
    }
    while(itBegin != itEnd)
    {
        this->_vector.push_back(*itBegin);
        itBegin++;
    }       
}

#endif
