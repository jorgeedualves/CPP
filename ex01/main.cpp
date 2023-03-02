/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:29:10 by joeduard          #+#    #+#             */
/*   Updated: 2023/03/02 16:16:39 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook objPhoneBook;
    int option;

    while(1)
    {
        std::cout << "Choose one option: " << std::endl;
        std::cout << "Option: 1 = Add, 2 = Seach, 3 = Exit" << std::endl;
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
