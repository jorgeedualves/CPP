/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:30:57 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/31 21:34:03 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
  this->_index = 0;
  this->_count = 0;
}

PhoneBook::~PhoneBook(void)
{
  return;
}

void PhoneBook::addContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
  this->_contacts[this->_index].setFirstName(firstName);
  this->_contacts[this->_index].setLastName(lastName);
  this->_contacts[this->_index].setNickName(nickName);
  this->_contacts[this->_index].setPhoneNumber(phoneNumber);
  this->_contacts[this->_index].setDarkestSecret(darkestSecret);
	if(this->_count < 8)
		this->_count++;
	this->_index++;
	if(this->_index >= 8)
		this->_index %= 8;
}

void PhoneBook::searchContact(int index)
{
    if(index >= 0 && index < this->_count && index < 8)
        printOneContact(this->_contacts[index]);
    else
        std::cout << "Invalid index!" << std::endl;
}

void PhoneBook::formatPrinting(std::string str)
{
  if (str.length() > 9)
    std::cout << std::right << std::setw(10) << str.substr(0, 9) + '.';
  else
    std::cout << std::right << std::setw(10) << str;
}

void PhoneBook::printAllContacts(void)
{
    std::cout << "|    Index  |First Name | Last Name | NickName  |" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    for (int i = 0; i < this->_count; i++)
    {
      std::cout << "| ";
      std::cout << std::right << std::setw(10) << i + 1;
      std::cout << "| ";
      formatPrinting(this->_contacts[i].getFirstName());
      std::cout << "| ";
      formatPrinting(this->_contacts[i].getLastName());
      std::cout << "| ";
      formatPrinting(this->_contacts[i].getNickName());
      std::cout << "| " << std::endl;
      std::cout << std::endl;
    }
}

void PhoneBook::printOneContact(Contact contact)
{
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickName() << std::endl;
    std::cout << "Phone Number" << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

int PhoneBook::getContactsCount(void)
{
  return (this->_count);
}
