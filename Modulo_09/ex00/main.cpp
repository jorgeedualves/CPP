/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:25:39 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 13:25:40 by joeduard         ###   ########.fr       */
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
