/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:40:58 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/08 11:43:43 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
: _name(name), _typen(weapon) {   
    return;
}
void HumanA::attack() const
{
    std::cout << this->_name << " attacks with their " << this->_typen.getType() << std::endl;    
}

