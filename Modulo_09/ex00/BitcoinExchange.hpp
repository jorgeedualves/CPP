/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:59:38 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/23 22:14:13 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <map>

struct BitcoinExchange
{
    std::map<std::string, double> _map;
};

void        bitcoinExchange(std::string cvsFileName, std::string txtFileName);
void        getBitcoinData(BitcoinExchange &bitcoinData, std::string fileName);
void        readInputAndExchangeData(BitcoinExchange &bitcoinData, std::string fileName);
double      exchangeRate(BitcoinExchange bitcoinData, std::string date);
std::string pastDate(std::string date);
bool        validDate(const std::string &date);

#endif
