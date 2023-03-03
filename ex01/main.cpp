/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:29:10 by joeduard          #+#    #+#             */
/*   Updated: 2023/03/02 22:16:56 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void addContact(PhoneBook &objPhoneBook)
{
	std::string firstName;
    std::string lastName;
	std::string nickName;
    std::string phoneNumber;
    std::string darkestSecrect;

	std::cin.ignore();	
	std::cout << "Input First Name: " << std::endl;
	std::getline(std::cin, firstName);
	std::cout << "Input Last Name: " << std::endl;
	std::getline(std::cin, lastName);
	std::cout << "Input Nick Name: " << std::endl;
	std::getline(std::cin, nickName);
	std::cout << "Input Phone Number: " << std::endl;
	std::getline(std::cin, phoneNumber);
	std::cout << "Input darkest Secrect: " << std::endl;
	std::getline(std::cin, darkestSecrect);
	objPhoneBook.addContact(firstName, lastName, nickName, phoneNumber, darkestSecrect);
	std::cout << "Contact " << firstName << " added to your phonebook." << std::endl;
}

void searchContact(PhoneBook objPhoneBook)
{
	std::string opt;
	std::stringstream ss;
	int index;

	if(objPhoneBook.getContactsCount() == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}
	objPhoneBook.printAllContacts();
	std::cout << "Choose a contact by index: " << std::endl;
	std::cin >> opt;
	ss << opt;
	ss >> index;
	objPhoneBook.searchContact(index - 1);
}

int main(void)
{
    PhoneBook objPhoneBook;
    int option;

    while(1)
    {
        std::cout << "Choose one option: " << std::endl;
        std::cout << "Option: 1 = Add | 2 = Seach | 3 = Exit" << std::endl;
        std::cin >> option;

        if(option == 1)
        {
            addContact(objPhoneBook);  
        }
        else if( option == 2)
        {
            searchContact(objPhoneBook);
        }
        else if (option == 3)
        {
            break;
        }
        else
        {
            std::cout << "Ivalid option" << std:: endl;
        }
    }
    return (0);
}
