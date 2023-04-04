/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:22:15 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/04 13:45:01 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    return;
}

void Harl::debug(void)
{
    std::cout <<
    "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
    " I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout <<
    "I cannot believe adding extra bacon costs more money. You didn't put"
    " enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout <<
    "I think I deserve to have some extra bacon for free. I've been coming for"
    " years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout <<
	"This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string vtLevel[4]= {"debug", "info", "warning", "error"};
    void (Harl::*ptFuncs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};


	for(int i = 0; i < 4; i++)
    {   
        if(!vtLevel[i].compare(level))
        {
            (this->*ptFuncs[i])();
            return;
        } 
    }
	return;
}
