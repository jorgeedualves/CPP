/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:36:22 by azamario          #+#    #+#             */
/*   Updated: 2023/07/13 13:16:00 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <stdint.h>

struct Data
{
    float length;
    float width; 
	float area;
    Data(void);
};

class Serializer
{
    public:
        ~Serializer(void);
        Serializer&         operator=(const Serializer& src);

        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);
        static void         calculateRectangleArea(Data* data);    

	private:
        Serializer(void);
        Serializer(const Serializer& src) ;	
};

std::ostream &operator<<(std::ostream &outputStream, const Data &data);

#endif
