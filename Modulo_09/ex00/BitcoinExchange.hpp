/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:25:29 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 13:25:31 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <istream>
#include <map>

struct BitcoinExchange
{
    std::map<std::string, double> _map;
};

void        bitcoinExchange(std::string csvFile, std::string txtFile);
void        getBitcoinData(BitcoinExchange &bitcoinData, std::string file);
void        readInputAndExchangeData(BitcoinExchange &bitcoinData, std::string file);
double      exchangeRate(BitcoinExchange bitcoinData, std::string date);
std::string pastDate(std::string date);
bool        ValidDate(const std::string &date);

#endif
