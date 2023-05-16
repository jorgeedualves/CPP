/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:39:59 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/12 17:21:47 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main (void)
{
    Data       data;
    Data      *deserialized = NULL;
    uintptr_t  serialized;
    Serializer retangule;

    std::cout << "\n-------- Original Data: --------\n";
    std::cout << data;
    std::cout << "Calcule Retangule: " << retangule.calculateRectangleArea(&data) << "\n";

    std::cout << "\n------- Serialized Data: -------\n";

    serialized = Serializer::serialize(&data);

    std::cout << serialized << "\n";

    std::cout << "\n";
    std::cout << "------ Deserialized Data: ------" << "\n";

    deserialized = Serializer::deserialize(serialized);
    
    std::cout << *deserialized;
     std::cout << "Calcule Retangule: " << retangule.calculateRectangleArea(&data) << "\n";
    std::cout << "\n";

    return (0);
}