/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:29:56 by joeduard          #+#    #+#             */
/*   Updated: 2023/06/07 10:44:15 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "1 " << std::endl;
    ClapTrap clapTrap("Megazord");
    ScavTrap scavTrap("Daimon");
    FragTrap fragTrap("Robocop");
  
    std::cout << "\n";
    std::cout << "2 " << std::endl;
    std::cout << clapTrap << "\n";
    std::cout << scavTrap << "\n";
    std::cout << fragTrap<< "\n";

    std::cout << "3 " << std::endl;
    clapTrap.attack(scavTrap.getName());
    scavTrap.takeDamage(clapTrap.getAD());
    clapTrap.beRepaired(50);
    std::cout << "\n";

    std::cout << "4 " << std::endl;
    scavTrap.attack(clapTrap.getName());
    clapTrap.takeDamage(scavTrap.getAD());
    scavTrap.guardGate();
    scavTrap.beRepaired(10);
    std::cout << "\n";

    std::cout << "5 " << std::endl;
    fragTrap.attack(scavTrap.getName());
    scavTrap.takeDamage(fragTrap.getAD());
    fragTrap.highFivesGuys();
    fragTrap.beRepaired(40);
    std::cout << "\n";

    std::cout << "6 " << std::endl;
    fragTrap.attack(scavTrap.getName());
    scavTrap.takeDamage(fragTrap.getAD());
    fragTrap.attack(scavTrap.getName());
    scavTrap.takeDamage(fragTrap.getAD());
    fragTrap.attack(scavTrap.getName());
    scavTrap.takeDamage(fragTrap.getAD());
    std::cout << "\n";

    std::cout << "7 " << std::endl;
    std::cout << clapTrap << "\n";
    std::cout << scavTrap << "\n";
    std::cout << fragTrap << "\n";

    return (0);
}