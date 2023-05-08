/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:39:48 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/08 11:43:43 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
    _typen = name;
    return;
}

const std::string &Weapon::getType()
{ 
    return this->_typen;
}
    
void Weapon::setType(std::string type)
{ 
    this->_typen = type;
}