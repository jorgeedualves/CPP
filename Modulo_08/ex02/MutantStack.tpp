/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:42:06 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/19 18:31:54 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
    return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
    return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin(void) const
{
    return (this->c.cbegin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend(void) const
{
    return (this->c.cend());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void)
{
    return (this->rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void)
{
    return(this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin(void) const
{
    return (this->c.crbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend(void) const
{
    return (this->c.crend());
}

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
    return;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& src) : std::stack<T>()
{
    *this = src;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
    return;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& rhs)
{
    std::stack<T>::operator=(rhs);
    return (*this);
}

#endif