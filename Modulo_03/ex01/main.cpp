/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:29:56 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/24 13:33:11 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
  ClapTrap clapTrap("Megazord");
  ScavTrap scavTrap("Daimon");
  
  std::cout << "\n";
  std::cout << clapTrap << "\n";
  std::cout << scavTrap << "\n";

  clapTrap.attack(scavTrap.getName());
  scavTrap.takeDamage(clapTrap.getAD());
  scavTrap.guardGate();
  scavTrap.beRepaired(1);
  std::cout << "\n";

  scavTrap.attack(clapTrap.getName());
  clapTrap.takeDamage(scavTrap.getAD());
  scavTrap.guardGate();
  scavTrap.beRepaired(1);
  std::cout << "\n";

  std::cout << clapTrap << "\n";
  std::cout << scavTrap << "\n";

  return (0);
}