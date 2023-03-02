/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:16:39 by joeduard          #+#    #+#             */
/*   Updated: 2023/03/02 15:12:10 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName(void)
{
    return (this->firstName);
}

std::string Contact::getLastName(void)
{
    return (this->lastName);
}

std::string Contact::getNickName(void)
{
    return (this->nickName);
}

std::string Contact::getPhoneNumber(void)
{
    return (this->phoneNumber);
}

std::string Contact::getDarkestSecret(void)
{
    return (this->darkestSecrect);
}