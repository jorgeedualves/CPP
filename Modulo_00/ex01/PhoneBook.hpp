/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:52:42 by joeduard          #+#    #+#             */
/*   Updated: 2023/03/06 20:37:03 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "Contact.hpp"
class PhoneBook
{
    private:
        Contact _contacts[8];
        int _index;
        int _count;

    public:
        PhoneBook(void);
        ~PhoneBook(void);

    	void addContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
    
    	void printOneContact(Contact contact);

        void formatPrinting(std::string str);
    
    	void printAllContacts(void);

    	void searchContact(int index);

		int getContactsCount(void);
};

#endif
