/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:20:07 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/10 12:46:46 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
    if(argc == 2)
    {
        const std::string raw(argv[1]);
        ScalarConverter convert(raw);

        std::cout << convert.castingChar() << "\n";
        std::cout << convert.castingInt() << "\n";
        std::cout << convert.castingfloat() << "\n";
        std::cout << convert.castingDouble() << "\n";
    }
    else
    {
        std::cerr << "Insert one valid string ou char!\n";
        std::cerr << "Example: \"c\", \"-42\", \"-4.2f\"\n";
        return(1);
    }
    return(0);
}