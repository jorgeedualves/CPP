/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:51:26 by joeduard          #+#    #+#             */
/*   Updated: 2023/03/23 22:11:54 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{

    private:
        std::string _name;
        Weapon *_weapon;
    public:
        explicit HumanB(std::string);
        ~HumanB() {}
        void attack() const;
        void setWeapon(Weapon &weapon); 
};
#endif