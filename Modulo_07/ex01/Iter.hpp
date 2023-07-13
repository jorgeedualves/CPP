/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:21:35 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 13:21:37 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* array, size_t lenght, void (*f)(const T&))
{
    for(size_t i = 0; i < lenght; i++)
        f(array[i]);
}

template <typename T>
void printArray(const T& n)
{
    std::cout << n << " ";
}

#endif
