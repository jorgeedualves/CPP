/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:21:15 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/24 16:16:21 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    std::cout << "FragTrap defaut constructor called\n";
    this->setName("FragTrap");
    this->setHP(100);
    this->setEP(100);
    this->setAD(30);
    return;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
    std::cout << "FragTrap parametric constructor called\n";
    this->setHP(100);
    this->setEP(100);
    this->setAD(30);
    return;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap()
{
    std::cout << "FragTrap Copy constructor called\n";
    *this = src;
    return;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FlagTrap Destructor called\n";
    return;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
    std::cout << " FragTrap Copy assignment operator called\n";
    const_cast<std::string &> (this->_name) = rhs.getName();
    this->_hitPoint = rhs.getHP();
    this->_energyPoint = rhs.getEP();
    this->_attackDamage = rhs.getAD();
    return (*this);
}

void FragTrap::highFiveGuys(void)
{
    if(this->getHP() == 0)
    {
        std::cout << this->getName()
                  << " is dead!. He cannot be display a positive high fives\n";
        return;
    }
    std::cout << "✋\n";
}

