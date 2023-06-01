/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:29:10 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/31 21:41:16 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>

bool fieldValidation(std::string input, std::string fieldName)
{
	bool onlyNewline = true;
    
    for (std::string::iterator i = input.begin(); i != input.end(); ++i)
    {
        if (*i != '\n')
        {
            onlyNewline = false;
            break;
        }
    }
    if (onlyNewline)
    {
        std::cout << "Empty field not allowed: " << fieldName << "\n\n";    
        return (false);
    }
	for (std::string::iterator i = input.begin(); i != input.end(); ++i)
	{
		if(!std::isalnum(*i))
		{
			std::cout << fieldName << " - Character not allowed: " << *i << std::endl;
			return (false);
		}
	}
	return (true);
}

bool phoneValidation(std::string input, std::string fieldName)
{
	bool onlyNewline = true;
    
    for (std::string::iterator i = input.begin(); i != input.end(); ++i)
    {
        if (*i != '\n')
        {
            onlyNewline = false;
            break;
        }
    }
    if (onlyNewline)
    {
        std::cout << "Empty field not allowed: " << fieldName << "\n\n";    
        return (false);
    }
	for (std::string::iterator i = input.begin(); i != input.end(); ++i)
	{
		if(!std::isdigit(*i))
		{
			std::cout << fieldName << " - Character not allowed: " << *i << std::endl;
			return(false);
		}
	}
	return (true);
}

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
	if(!fieldValidation(firstName, "First Name"))
		return;
	std::cout << "Input Last Name: " << std::endl;
	std::getline(std::cin, lastName);
	if(!fieldValidation(lastName, "Last Name"))
		return;
	std::cout << "Input Nick Name: " << std::endl;
	std::getline(std::cin, nickName);
	if(!fieldValidation(nickName, "Nick Name"))
		return;
	std::cout << "Input Phone Number: " << std::endl;
	std::getline(std::cin, phoneNumber);
	if(!phoneValidation(phoneNumber, "Phone Number"))
		return;
	std::cout << "Input darkest Secrect: " << std::endl;
	std::getline(std::cin, darkestSecrect);
	objPhoneBook.addContact(firstName, lastName, nickName, phoneNumber, darkestSecrect);
	std::cout << std::endl << "Contact " << firstName << " added to your phonebook." << std::endl;
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
    std::string option;

    while(1)
    {
        std::cout << "Choose one option: " << std::endl;
        std::cout << "Option: ADD | SEARCH | EXIT" << std::endl;
        std::cin >> option;

        if(option == "ADD")
            addContact(objPhoneBook);  
        else if( option == "SEARCH")
            searchContact(objPhoneBook);
        else if (option == "EXIT")
            break;
		else if (std::cin.eof())
		{
         	std::cout << "\nCTRL + D not allowed | Invalid option\n" << std::endl;
			break;
		}           
        else
        	std::cout << "Invalid option" << std:: endl;
    }
    return (0);
}
