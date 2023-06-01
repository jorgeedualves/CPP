/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:39:48 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/31 22:08:11 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
    _type = name;
    return;
}

const std::string &Weapon::getType()
{ 
    return this->_type;
}
    
void Weapon::setType(std::string type)
{ 
    this->_type = type;
}