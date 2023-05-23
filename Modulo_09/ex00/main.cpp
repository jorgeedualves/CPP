/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:55:02 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/23 18:55:11 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main( int argc, char *argv[] )
{
    if (argc != 2)
    {
        std::cout << "Usage: btc <filename>" << std::endl;
        return (1);
    }

    std::string csvFileName;
    std::string txtFileName;

    csvFileName = "data.csv";
    txtFileName = argv[1];

    bitcoinExchange(csvFileName, txtFileName);

    return (0);
}
