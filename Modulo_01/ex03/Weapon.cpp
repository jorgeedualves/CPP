/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:39:48 by joeduard          #+#    #+#             */
/*   Updated: 2023/03/23 20:54:30 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
    _weapon = name;
    return;
}

const std::string &Weapon::getType()
{ 
    return this->_weapon;
}
    
void Weapon::setType(std::string type)
{ 
    this->_weapon = type;
}