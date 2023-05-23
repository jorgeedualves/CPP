/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:09:42 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/23 19:01:58 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void        bitcoinExchange(std::string cvsFileName, std::string txtFileName)
{
    BitcoinExchange bitcoinData;

    getBitcoinData(bitcoinData, cvsFileName);
    readInputAndExchangeData(bitcoinData, txtFileName);
}

void        getBitcoinData(BitcoinExchange &bitcoinData, std::string fileName)
{
    std::ifstream file;
    std::string line;

    file.open(fileName.c_str());
    getline(file, line);

    while (getline(file, line))
    {
        std::istringstream  stringStream;
        std::string         date;
		double				value;

		stringStream.str(line);
		getline(stringStream, date, ',');
		stringStream >>value;
		bitcoinData._map.insert(std::make_pair(date, value));
    }
}

void        readInputAndExchangeData(BitcoinExchange &bitcoinData, std::string fileName)
{	
	std::ifstream	file;
	std::string		line;

	file.open(fileName.c_str());
	getline(file, line);

	if (!(line == "date | value"))
	{
		std::cout << "Error: badinput => \"" << line << "\"" << std::endl;
		return;
	}
	while (getline(file, line))
	{
		std::string delimiter = " | ";
		std::string date;
		std::string stringValue;

		size_t pos = line.find(delimiter);
		if (pos == 10)
		{
			date = line.substr(0,pos);
			stringValue = line.substr(pos + delimiter.length());
		}
		else
		{
			date = line;
			stringValue = "";

		}

		double value = std::atof(stringValue.c_str());
		if (value > 1000)
			std::cerr << "Error: too letge number\n";
		else if (pos != 10 || !validDate(date))
			std::cerr << "Error: bad input => | " << date << " | \n";
		else if (value < 0)
			std:: cerr << "Error: not a positive number\n";
		else
			std::cout << date << " => " << value << " = " << value * exchangeRate(bitcoinData, date) << std::endl;
	}

}

double      exchangeRate(BitcoinExchange bitcoinData, std::string date)
{
	std::map<std::string, double>::iterator it = bitcoinData._map.find(date);

	if (it != bitcoinData._map.end())
		return (it->second);
	else
	{
		date = pastDate(date);
		return (exchangeRate(bitcoinData, date));
	}
}

std::string pastDate(std::string date)
{
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (day == 1)
	{
		if (month == 1)
		{
			month = 12;
			year--;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			month--;
			day = 31;
		}
		else if (month == 3)
		{
			month--;
			if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))
				day = 28;
			else
				day = 29;
		}
		else
		{
			month--;
			day = 30;
		}
	}
	else
	{
		day--;
	}

		std::stringstream str;
		str << std::setw(4) << std::setfill('0') << year << "-"
			<< std::setw(2) << std::setfill('0') << month << "-"
			<< std::setw(2) << std::setfill('0') << day;

		date = str.str();
		return (date);
}

bool        validDate(const std::string &date)
{
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);

	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (year < 2009 || year > 2023)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	if (month == 2)
	{
		if (day > 29)
			return (false);
		if (day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)))
			return (false);
	}
	return (true);

}
