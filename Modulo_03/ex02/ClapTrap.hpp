/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:49:07 by joeduard          #+#    #+#             */
/*   Updated: 2023/06/05 21:35:37 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include<string>

class ClapTrap{

    public:
        ClapTrap(void);
        explicit ClapTrap(std::string const name);
        ClapTrap(ClapTrap const &src);
        ~ClapTrap(void);

        ClapTrap &operator=(ClapTrap const &rhs);

        std::string getName(void) const;
        std::string getClassName(void) const;
        unsigned int getHP(void) const;
        unsigned int getEP(void) const;
        unsigned int getAD(void) const;

        void setName(std::string const &name);
        void setClassName(std::string const &className);
        void setHP(unsigned int hitPoints);
        void setEP(unsigned int EnergyPonts);
        void setAD(unsigned int attackDamage);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    protected:
    std::string const _name;
    std::string const _className;
    unsigned int _hitPoint;
    unsigned int _energyPoint;
    unsigned int _attackDamage;
};

std::ostream &operator<<(std::ostream &cout, ClapTrap const &cin);

#endif