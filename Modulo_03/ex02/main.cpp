/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:29:56 by joeduard          #+#    #+#             */
/*   Updated: 2023/06/05 21:47:57 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
  ClapTrap clapTrap("Megazord");
  ScavTrap scavTrap("Daimon");
  FragTrap fragTrap("Robocop");
  
  std::cout << "\n";
  std::cout << clapTrap << "\n";
  std::cout << scavTrap << "\n";
  std::cout << fragTrap<< "\n";

  clapTrap.attack(scavTrap.getName());
  scavTrap.takeDamage(clapTrap.getAD());
  clapTrap.beRepaired(50);
  std::cout << "\n";

  scavTrap.attack(clapTrap.getName());
  clapTrap.takeDamage(scavTrap.getAD());
  scavTrap.guardGate();
  scavTrap.beRepaired(50);
  std::cout << "\n";

  fragTrap.attack(scavTrap.getName());
  scavTrap.takeDamage(fragTrap.getAD());
  fragTrap.highFivesGuys();
  fragTrap.beRepaired(40);
  std::cout << "\n";

  std::cout << clapTrap << "\n";
  std::cout << scavTrap << "\n";
  std::cout << fragTrap << "\n";

  return (0);
}