/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:19:02 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 13:19:05 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"

int main(void)
{
    int int1 = 2;
    int int2 = 3;

    float float1 = 42.42;
    float float2 = 41.41;

    std::string string1 = "chaine1";
    std::string string2 = "chaine2";


	std::cout << "\nTEST 1: SWAP\n" << std::endl;
	
    std::cout << "[ Before Swap Int ]\n";
    std::cout << "int1 = " << int1 << ", int2 = " << int2 << std::endl;
    ::swap<int>(int1, int2);
    std::cout << "\n";
    std::cout << "[ After Swap Int ]\n";
    std::cout << "int1 = " << int1 << ", int2 = " << int2 << std::endl;
    std::cout << "\n";

    std::cout << "[ Before Swap Float ]\n";
    std::cout << "float1 = " << float1 << ", float2 = " << float2 << std::endl;
    ::swap(float1, float2);
    std::cout << "\n";
    std::cout << "[ After Swap Float ]\n";
    std::cout << "float1 = " << float1 << ", float2 = " << float2 << std::endl;
    std::cout << "\n";

    std::cout << "[ Before Swap String ]\n";
    std::cout << "string1 = " << string1 << ", strnig2 = " << string2 << std::endl;
    ::swap(string1, string2);
    std::cout << "\n";
    std::cout << "[ After Swap String ]\n";
    std::cout << "string1 = " << string1 << ", string2 = " << string2 << std::endl;
	std::cout << "\n";


	std::cout << "\nTEST 2: MAX\n" << std::endl;

    std::cout << "[ Max Int ]\n";
    std::cout << "int1 = " << int1 << ", int2 = " << int2 << std::endl;
    std::cout << "max(int1, int2) = " << ::max(int1, int2) << std::endl;
    std::cout << "\n";

    std::cout << "[ Max Float ]\n";
    std::cout << "float1 = " << float1 << ", float2 = " << float2 << std::endl;
    std::cout << "max(float1, float2) = " << ::max(float1, float2) << std::endl;
    std::cout << "\n";

    std::cout << "[ Max String ]\n";
    std::cout << "string1 = " << string1 << ", string2 = " << string2 << std::endl;
    std::cout << "max(string1, string2) = " << ::max(string1, string2) << std::endl;
    std::cout << "\n";


	std::cout << "\nTEST 3: MIN\n" << std::endl;

    std::cout << "[ Min Int ]\n";
    std::cout << "int1 = " << int1 << ", int2 = " << int2 << std::endl;
    std::cout << "min(int1, int2) = " << ::min(int1, int2) << std::endl;
    std::cout << "\n";

    std::cout << "[ Min Float ]\n";
    std::cout << "float1 = " << float1 << ", float2 = " << float2 << std::endl;
    std::cout << "min(float1, float2) = " << ::min(float1, float2) << std::endl;
    std::cout << "\n";

    std::cout << "[ Min String ]\n";
    std::cout << "string1 = " << string1 << ", string2 = " << string2 << std::endl;
    std::cout << "min(string1, string2) = " << ::min(string1, string2) << std::endl;
    std::cout << "\n";

    return (0);
}
