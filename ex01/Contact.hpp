/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:16:36 by joeduard          #+#    #+#             */
/*   Updated: 2023/03/02 15:12:14 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	//atributos
    private:
        std::string firstName;
        std::string lastName;
		std::string nickName;
        std::string phoneNumber;
        std::string darkestSecrect;
    
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
