/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:30:57 by joeduard          #+#    #+#             */
/*   Updated: 2023/03/02 16:04:02 by joeduard         ###   ########.fr       */
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
}

void PhoneBook::searchContact(int index)
{
    return ;
}

void PhoneBook::printAllContacts(void)
{
    std::cout << "| Index |   First Name   |   Last Name   |   NickName   |" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;

}

void PhoneBook::printOneContact(void)
{

}