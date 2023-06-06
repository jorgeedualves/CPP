/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:32:28 by joeduard          #+#    #+#             */
/*   Updated: 2023/06/05 22:51:13 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    return;
}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]\n" <<
    "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
    " I really do!\n\n";
}

void Harl::info(void)
{
    std::cout << "[ INFO ]\n" <<
    "I cannot believe adding extra bacon costs more money. You didn't put"
    " enough bacon in my burger! If you did, I wouldn't be asking for more!\n\n";
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]\n" <<
    "I think I deserve to have some extra bacon for free.\n" <<
    "I've been coming for years whereas you started working here since last month.\n\n";
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n" <<
	"This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
    int index = -1; 
    std::string harlNames[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for(int i = 0; i < 4; i++)
    {   
        if(level.compare(harlNames[i]) == 0)
            index = i;
    }

    switch (index)
    {
      case 0:
        debug();
        // fallthrough      
      case 1:
        info(); 
        // fallthrough
      case 2:
        warning();
        // fallthrough
      case 3:
        error();
        break;
      default:
          std::cout << "[ Probably complaining about insignificant problems ]\n";
          break;
    }
	return;
}
