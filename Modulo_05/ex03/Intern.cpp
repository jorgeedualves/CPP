/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:24:32 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/05 19:39:37 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern:: Construct Called\n";
    _forms[0] = new PresidentialPardonForm();
    _forms[1] = new RobotomyRequestForm();
    _forms[2] = new ShrubberyCreationForm();
    return;
}

Intern::Intern(const Intern& src)
{
    std::cout << "Intern:: Copy Constructor Called\n";
    _forms[0] = new PresidentialPardonForm();
    _forms[1] = new RobotomyRequestForm();
    _forms[2] = new ShrubberyCreationForm();
    (void)src;
}

Intern::~Intern()
{
    std::cout << "Intern: Destructor called" << std::endl;
    for (int i = 0; i < 3; ++i)
        delete _forms[i];
}
     
Intern &Intern::operator=(const Intern& rhs)
{
    (void)rhs;
    return (*this);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    for (int i = 0; i < 3; ++i)
    {   
        if(formName == this->_forms[i]->getName())
        {
            std::cout << "intern creates " << formName << "\n";
            return (this->_forms[i]->clone(target));
        }
    }
    std::cout << "Intern: Unknown form name!\n";
    return (0);
}
