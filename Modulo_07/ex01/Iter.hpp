/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:21:35 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/21 16:37:53 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* array, size_t lenght, void (*f)(T const &))
{   
    if(!array || !f)
        return;
    for(size_t i = 0; i < lenght; i++)
        f(array[i]);
}

template <typename T>
void printArray(const T& n)
{
    std::cout << n << " ";
}

template <typename T>
void iter(T* array, size_t lenght, void (*f)(T&))
{   
    if(!array || !f)
        return;
    for(size_t i = 0; i < lenght; i++)
        f(array[i]);
}

#endif

/*
Em resumo, o código fornece uma função genérica iter que pode ser usada para iterar sobre arrays e
aplicar uma função a cada elemento do array. Existem duas versões da função iter, uma para trabalhar
com arrays de tipos constantes e outra para trabalhar com arrays de tipos não constantes.
Essas funções podem ser úteis para realizar operações em arrays de diferentes tipos de dados de 
forma genérica e flexível. A função printArray é uma função auxiliar que imprime um valor no console.
*/