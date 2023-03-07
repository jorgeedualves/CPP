/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:16:36 by joeduard          #+#    #+#             */
/*   Updated: 2023/03/07 14:58:18 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class Contact
{
	//atributos
    private:
        std::string _firstName;
        std::string _lastName;
		std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecrect;
    
	//metodos
    public:
        std::string getFirstName(void);
        std::string getLastName(void);
		std::string getNickName(void);
        std::string getPhoneNumber(void);
        std::string getDarkestSecret(void);

		void setFirstName(std::string fistName);
        void setLastName(std::string lastName);
		void setNickName(std::string nickName);
        void setPhoneNumber(std::string phoneNumber);
        void setDarkestSecret(std::string darketSecret);

};
#endif
