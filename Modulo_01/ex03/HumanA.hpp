/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:47:14 by joeduard          #+#    #+#             */
/*   Updated: 2023/03/23 20:56:06 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"


class HumanA {

    private:
         std::string _name;
         Weapon &_weapon;
    public:
        HumanA(std::string, Weapon &weapon);
        ~HumanA() {}
        void attack() const; 
};
#endif