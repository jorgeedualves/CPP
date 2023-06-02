/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:11:08 by joeduard          #+#    #+#             */
/*   Updated: 2023/06/02 13:01:49 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("ClapTrap"), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
    std::cout << "ClapTrap Default constructor Called\n";
    return;
}

ClapTrap::ClapTrap(std::string const name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
    std::cout << "ClapTrap Parametric constructor Called\n";
    return;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
    std::cout << " ClapTrap Copy constructor Called\n";
    *this = src;
    return;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap Destructor called\n";
    return;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
    std::cout << " ClapTrap Copy assignment operator called\n";
    const_cast<std::string &> (this->_name) = rhs.getName();
    this->_hitPoint = rhs.getHP();
    this->_energyPoint = rhs.getEP();
    this->_attackDamage = rhs.getAD();
    return (*this);
}

std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

 unsigned int ClapTrap::getHP(void) const
 {
    return(this->_hitPoint);
 }

unsigned int ClapTrap::getEP(void) const
{
    return(this->_energyPoint);
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
    this->_hitPoint = hitPoints;
}

void ClapTrap::setEP(unsigned int EnergyPonts)
{
    this->_energyPoint = EnergyPonts;
}

void ClapTrap::setAD(unsigned int attackDamage)
{
    this->_attackDamage = attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->getHP() == 0)
    {
        std::cout << this->getName()
                  << " is dead!. He cannot not attack"
                  << target << std::endl;
        return;

    }
    if (this->getEP() == 0)
    {
        std::cout << "No energy remainig!"
                  << this->getName()
                  << " cannot attacks!" << target << std::endl;
        return;
    }
    std::cout << this->getName()
              << " attacks " << target
              << " causing " << this->getAD() 
              << "points of damage!\n";
    this->_energyPoint--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->getHP() == 0)
    {
         std::cout << this->getName()
                  << " is dead!. He cannot suffer damage\n";
        return;
    }
    std::cout << this->getName()
            << " suffered "
            << amount << " points of damage!\n";
    if (this->_hitPoint <= amount)
        this->_hitPoint = 0;
    else 
        this->_hitPoint -= amount;
    if(this->getHP() <= 0)
    {
        std::cout << this->getName()
                  << " has died!\n";   
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->getHP() == 0)
    {
         std::cout << this->getName()
                  << " is dead!. He cannot be repaired\n";
        return;

    }
    if(this->getEP() == 0)
    {
         std::cout << "No energy remainig!"
                  << this->getName()
                  << " cannot be repaired!\n";
        return;

    }
    std::cout << this->getName()
              << " recovered " << amount
              << " points of hit points!\n";
    if (this->_hitPoint + amount > 10)
        this->_hitPoint = 10;
    else
        this->_hitPoint += amount;
    this->_energyPoint--;
}

std::ostream &operator<<(std::ostream &out, ClapTrap const &in)
{
    out << "Name: " << in.getName() << "\n";
    out << "HP: " << in.getHP() << "\n";
    out << "EP: " << in.getEP() << "\n";
    out << "AD: " << in.getAD() << "\n";
    return (out);
}


