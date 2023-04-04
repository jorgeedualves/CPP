/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:00:33 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/03 22:38:11 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char* argv[])
{
    Harl harl;

    if(argc != 2)
    {
        std::cout << "Quantidade errada de parametros!" << std::endl;
        return (1);
    }
    harl.complain(argv[1]);

    return (0);
}