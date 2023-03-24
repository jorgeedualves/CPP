/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:55:11 by joeduard          #+#    #+#             */
/*   Updated: 2023/03/23 22:12:53 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) , _weapon(NULL){
    return;
}

void HumanB::attack() const
{
    std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl; 
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
} 