/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:18:40 by joeduard          #+#    #+#             */
/*   Updated: 2023/06/02 12:11:30 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strReplace.hpp"
#include <iostream>

bool fileInValidation(std::ifstream &fileIn, char *file)
{
	fileIn.open(file);
	if (fileIn.fail())
	{
		std::cerr << "Failed to open: " << file << std::endl;
		return (false);
	}
	if (fileIn.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "The file is empty.\n";
        return (false);
    } 
	return(true);
}

bool fileOutValidation(std::ofstream &fileOut, char *file)
{
	std::string fileReplace = std::string(file) + ".replace";
	fileOut.open(fileReplace.c_str()); // c_str ????
	if(fileOut.fail())
	{
		std::cerr << "Failed to create: " << fileReplace << std::endl;
		return (false);
	} 
	return (true);
}

int main(int argc, char *argv[])
{
    std::ifstream fileIn;  // Abrir o arquivo, procurar o s1 e trocar pelo s2 e salvar em file out
    std::ofstream fileOut;
    std::stringstream content;

    if (argc != 4)
    {
        std::cerr << "Invalid number of arguments\n";
        return (1);
    }
    else if (fileInValidation(fileIn, argv[1]) && fileOutValidation(fileOut, argv[1]))
	{
		content << fileIn.rdbuf();
		fileOut << replace(content.str(), argv[2] ,argv[3]);
		fileIn.close();
		fileOut.close();
	}
	else
		return(1);
    return (0);
}