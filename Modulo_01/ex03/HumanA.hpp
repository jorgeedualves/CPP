/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:47:14 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/08 11:43:43 by joeduard         ###   ########.fr       */
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
         Weapon &_typen;
    public:
        HumanA(std::string, Weapon &weapon);
        ~HumanA() {}
        void attack() const; 
};
#endif