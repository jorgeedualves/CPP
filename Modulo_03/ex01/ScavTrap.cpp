/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:29:47 by joeduard          #+#    #+#             */
/*   Updated: 2023/06/06 22:06:16 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

 ScavTrap::ScavTrap(void) : ClapTrap()
{
    std::cout << "ScavTrap Defaut Contructor Called\n";
    this->setName("ScavTrap");
    this->setClassName("ScavTrap");
    this->setHP(100);
    this->setEP(50);
    this->setAD(20);
    return;
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name)
{
    std::cout << "ScavTrap Parametric Contructor Called\n";
    this->setClassName("ScavTrap");
    this->setHP(100);
    this->setEP(50);
    this->setAD(20);
    return;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap()
{
      std::cout << "ScavTrap Copy Contructor Called\n";
      *this = src;
      return;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap Destructor Called\n";
    return;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "ScavTrap Copy Assigment Called\n";
    const_cast<std::string &> (this->_name) = rhs.getName();
    this->_hitPoints = rhs.getHP();
    this->_energyPoints = rhs.getEP();
    this->_attackDamage = rhs.getAD();
    return (*this);

}

void ScavTrap::attack(const std::string& target)
{
    if (this->getHP() == 0)
    {
        std::cout << this->getClassName() << " " << this->getName()
                  << " is dead!. He cannot not attack"
                  << target << std::endl;
        return;
    }
    if (this->getEP() == 0)
    {
        std::cout << "No energy remainig!"
                  << this->getClassName() << " " << this->getName()
                  << " cannot attacks!" << target << std::endl;
        return;
    }
    std::cout << this->getClassName() << " " << this->getName()
              << " attacks " << target
              << " causing " << this->getAD() 
              << " points of damage!" << std::endl;
    this->_energyPoints--;   
}

void ScavTrap::guardGate(void) const
{
    if (this->getHP() == 0)
    {
        std::cout << "ScavTrap " << this->getName() << " is dead!. He cannot enter in Gate Keeper mode\n";
        return;
    }
    std::cout << "ScavTrap " << this->getName() << " is now Gate Keeper mode\n";
}