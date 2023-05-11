/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:36:20 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/11 12:53:07 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
    float lenght;
    float width;

    Data(void);
};


class Serializer
{
    public:
        Serializer(void);
        Serializer(const Serializer&);
        ~Serializer(void);

        Serializer& operator=(const Serializer& rhs);

        float calculateRectangleArea(Data* data);
        
        static uintptr_t serialize(Data* ptr);
        static Data *deserialize(uintptr_t raw);

};

std::ostream &operator<<( std::ostream &cout, const Data &data);

#endif