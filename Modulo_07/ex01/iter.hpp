/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:42:03 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/17 10:52:26 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T* addr, size_t lenght, void (*f)(const T&))
{
    for (size_t i = 0; i < lenght; i++)
        f(addr[i]);
}

template <typename T>
void printArr(const T& x)
{
    std::cout << x << " ";
}

#endif