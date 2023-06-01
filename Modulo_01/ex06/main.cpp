/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:48:08 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/31 21:52:01 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char* argv[])
{
    Harl harl;

    if(argc != 2)
    {
        std::cerr << "Wrong amount of parameters!" << std::endl;
        return (1);
    }
    harl.complain(argv[1]);

    return (0);
}