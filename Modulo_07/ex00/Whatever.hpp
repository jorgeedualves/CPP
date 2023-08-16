/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:19:12 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/21 16:35:08 by joeduard         ###   ########.fr       */
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

/*
O código utiliza templates em C++, o que permite a criação de funções genéricas que podem trabalhar
com diferentes tipos de dados, proporcionando maior reuso e flexibilidade no código.
As funções swap, min e max podem ser usadas com tipos primitivos (como inteiros e números de
ponto flutuante) ou com objetos personalizados, desde que os operadores de comparação (<, >) 
e atribuição (=) sejam definidos para esses objetos.
*/