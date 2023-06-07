/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:11:08 by joeduard          #+#    #+#             */
/*   Updated: 2023/06/06 22:19:01 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("ClapTrap"), _className("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Default constructor Called\n";
    return;
}

ClapTrap::ClapTrap(std::string const name) : _name(name), _className("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
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
    this->_hitPoints = rhs.getHP();
    this->_energyPoints = rhs.getEP();
    this->_attackDamage = rhs.getAD();
    return (*this);
}

std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

std::string ClapTrap::getClassName(void) const
{
	return (this->_className);
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

void ClapTrap::setClassName(std::string const &className)
{
	const_cast<std::string &>(this->_className) = className;
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
              << "points of damage!" << std::endl;
    this->_energyPoints--;   
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->getHP() == 0)
    {
        std::cout << this->getClassName() << " " << this->getName()
                  << " is dead!. He cannot suffer damage" << std::endl;
        return;
    }
    std::cout << this->getClassName() << " " << this->getName()
              << " suffered " << amount << " points of damage!\n";
    if (this->_hitPoints <= amount)
        this->_hitPoints = 0;
    else 
        this->_hitPoints -= amount;
    if (this->getHP() <= 0)
    {
        std::cout << this->getClassName() << " " << this->getName()
                  << " has died!" << std::endl;   
    }  
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->getHP() == 0)
    {
        std::cout << this->getClassName() << " " << this->getName()
                  << " is dead!. He cannot be repaired" << std::endl;
        return;
    }
    if (this->getEP() == 0)
    {
        std::cout << "No energy remainig!"
                  << this->getClassName() << " " << this->getName()
                  << " cannot be repaired!" <<std::endl;
        return;
    }
    std::cout << this->getClassName() << " " << this->getName()
              << " recovered " << amount
              << " points of hit points!\n";
    this->_hitPoints += amount;
    this->_energyPoints--; 
}

std::ostream &operator<<(std::ostream &cout, ClapTrap const &cin)
{
    cout << "Class: " << cin.getClassName() << "\n";
    cout << "Name: " << cin.getName() << "\n";
    cout << "HP: " << cin.getHP() << "\n";
    cout << "EP: " << cin.getEP() << "\n";
    cout << "AD: " << cin.getAD() << "\n";
    return (cout);
}


