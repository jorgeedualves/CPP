/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:11:08 by joeduard          #+#    #+#             */
/*   Updated: 2023/06/06 22:06:15 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor Called\n";
    return;
}

ClapTrap::ClapTrap(std::string const name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Parametric constructor Called\n";
    return;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
    std::cout << "Copy constructor Called\n";
    *this = src;
    return;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called\n";
    return;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
    std::cout << "Copy assignment operator called\n";
    const_cast<std::string &> (this->_name) = rhs.getName();
    this->_hitPoints = rhs.getHP();
    this->_energyPoints = rhs.getEP();
    this->_attackDamage = rhs.getAD();
    return (*this);
}

std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

 unsigned int ClapTrap::getHP(void) const
 {
    return(this->_hitPoints);
 }

unsigned int ClapTrap::getEP(void) const
{
    return(this->_energyPoints);
}

unsigned int ClapTrap::getAD(void) const
{
    return (this->_attackDamage);
}

void ClapTrap::setName(std::string const &name)
{
    const_cast<std::string &>(this->_name) = name;
}

void ClapTrap::setHP(unsigned int hitPoints)
{
    this->_hitPoints = hitPoints;
}

void ClapTrap::setEP(unsigned int EnergyPonts)
{
    this->_energyPoints = EnergyPonts;
}

void ClapTrap::setAD(unsigned int attackDamage)
{
    this->_attackDamage = attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->getHP() == 0)
    {
        std::cout << "ClapTrap " << this->getName()
                  << " is dead! He cannot not attack "
                  << target << std::endl;
        return;

    }
    if (this->getEP() == 0)
    {
        std::cout << "No energy remainig!"
                  << " ClapTrap " << this->getName()
                  << " cannot attacks " << target << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->getName()
              << " attacks " << target
              << " causing " << this->getAD() 
              << " points of damage!\n";
    this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->getHP() == 0)
    {
         std::cout << "ClapTrap " << this->getName()
                  << " is dead!. He cannot suffer damage!\n";
        return;
    }
    std::cout << "ClapTrap "
            << this->getName()
            << " suffered "
            << amount << " points of damage!\n";
    if (this->_hitPoints <= amount)
        this->_hitPoints = 0;
    else 
        this->_hitPoints -= amount;
    if(this->getHP() <= 0)
    {
        std::cout << "ClapTrap " << this->getName()
                  << " has died!\n";   
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->getHP() == 0)
    {
         std::cout << "ClapTrap " << this->getName()
                  << " is dead! He cannot be repaired!\n";
        return;

    }
    if(this->getEP() == 0)
    {
         std::cout << "No energy remainig!"
                  << " ClapTrap " << this->getName()
                  << " cannot be repaired!\n";
        return;

    }
    std::cout << "ClapTrap " << this->getName()
              << " recovered " << amount
              << " points of hit points!\n";
   
    this->_hitPoints += amount;
    this->_energyPoints--;
}

std::ostream &operator<<(std::ostream &out, ClapTrap const &in)
{
    out << "Name: " << in.getName() << "\n";
    out << "HP: " << in.getHP() << "\n";
    out << "EP: " << in.getEP() << "\n";
    out << "AD: " << in.getAD() << "\n";
    return (out);
}


