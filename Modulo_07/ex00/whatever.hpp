/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:42:39 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/16 18:19:07 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
const T& min(const T& a, const T& b)
{
    return((a < b) ? a : b);
}

template <typename T>
const T& max(const T& a, const T& b)
{
    return((a > b) ? a : b);
}

#endif