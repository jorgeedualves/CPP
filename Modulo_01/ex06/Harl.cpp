/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:32:28 by joeduard          #+#    #+#             */
/*   Updated: 2023/06/02 12:59:39 by joeduard         ###   ########.fr       */
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
    " I really do!\n";
}

void Harl::info(void)
{
    std::cout << "[ INFO ]\n" <<
    "I cannot believe adding extra bacon costs more money. You didn't put"
    " enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]\n" <<
    "I think I deserve to have some extra bacon for free.\n" <<
    "I've been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n" <<
	"This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
    std::string vtLevel[4]= {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*ptFuncs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    size_t opt;

	for(opt = 0; opt < 4; opt++)
    {   
        if(!vtLevel[opt].compare(level))
            break;
    }

    switch (opt)
    {
    case 0:
    { (this->*ptFuncs[0])();
      std::cout << std::endl;
      __attribute__((fallthrough));
    }
     case 1:
    { (this->*ptFuncs[1])();
      std::cout << std::endl;
      __attribute__((fallthrough));
    }
     case 2:
    { (this->*ptFuncs[2])();
      std::cout << std::endl;
      __attribute__((fallthrough));
    }
     case 3:
    { (this->*ptFuncs[3])();
      std::cout << std::endl;
      break;
    }
    default:
        std::cout << "[ Probably complaining about insignificant problems ]\n";
        break;
    }
	return;
}
