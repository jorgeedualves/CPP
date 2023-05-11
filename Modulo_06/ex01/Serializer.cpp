/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:09:31 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/11 12:52:09 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Data::Data(void) : lenght(10), width(50)
{
    return;
}


Serializer::Serializer(void)
{
    std::cout << "Default Constructor Called\n";
    return;
}

Serializer::Serializer(const Serializer &src)
{
     std::cout << "Copy Constructor Called\n";
    (void) src;
}

Serializer::~Serializer(void)
{
    std::cout << "Destructor Called\n";
    return;
}

Serializer& Serializer::operator=(const Serializer& rhs)
{
    (void) rhs;
    return (*this);
}


float Serializer::calculateRectangleArea(Data* data)
{
    return(data->lenght * data->width);
}

uintptr_t Serializer::serialize(Data* ptr )
{
    return(reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw )
{
    return(reinterpret_cast<Data*>(raw));
}

std::ostream &operator<<( std::ostream &cout, const Data &data)
{
  cout << "Largura: " << data.lenght << "\nLargura: " << data.width << "\n";

  return (cout);
}
