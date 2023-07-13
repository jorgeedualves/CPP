/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:14:57 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 13:15:02 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main( void )
{
    Data       data;
    Data      *deserialized = NULL;
    uintptr_t  serialized;

    std::cout << "\n-------- Original Data: --------\n" << std::endl;
    Serializer::calculateRectangleArea(&data);
    std::cout << data << std::endl;
    
    std::cout << "\n------- Serialized Data: -------\n" << std::endl;
    serialized = Serializer::serialize(&data);
	std::cout << serialized << std::endl;

    std::cout << "\n------ Deserialized Data: ------\n" << std::endl;
    deserialized = Serializer::deserialize(serialized);    
    std::cout << *deserialized << std::endl;
    
    return (0);
}
