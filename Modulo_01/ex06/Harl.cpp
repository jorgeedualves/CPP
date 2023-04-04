/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:32:28 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/04 17:17:58 by joeduard         ###   ########.fr       */
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
    " I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]\n" <<
    "I cannot believe adding extra bacon costs more money. You didn't put"
    " enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]\n" <<
    "I think I deserve to have some extra bacon for free.\n" <<
    "I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n" <<
	"This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string vtLevel[4]= {"debug", "info", "warning", "error"};
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
        std::cout << "[ Probably complaining about insignificant problems ]";
        break;
    }

	return;
}
