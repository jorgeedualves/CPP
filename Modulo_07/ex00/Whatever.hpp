/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:19:12 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 13:21:14 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_CPP
#define WHATEVER_CPP

#include <iostream>

template <typename T> 
void swap(T &a, T &b)
{
    T temp;
    
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
const T& min(const T &a, const T &b)
{
    return (a < b) ? a : b;
}

template <typename T>
const T& max(const T &a, const T &b)
{
    return (a > b) ? a : b;
}

#endif
