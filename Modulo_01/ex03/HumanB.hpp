/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:51:26 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/08 11:43:43 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{

    private:
        std::string _name;
        Weapon *_typen;
    public:
        explicit HumanB(std::string);
        ~HumanB() {}
        void attack() const;
        void setWeapon(Weapon &weapon); 
};
#endif