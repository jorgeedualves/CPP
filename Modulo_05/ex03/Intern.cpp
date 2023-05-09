/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:47:44 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/08 22:28:21 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "[Intern:: Constructor called]\n";
    return;
}

Intern::Intern(const Intern& src) 
{
    std::cout << "[Intern:: Copy Constructor called]\n";
    *this = src;
}

Intern::~Intern(void)
{
     std::cout << "[Intern:: Destructor called]\n";
}

Intern& Intern::operator=(const Intern& rhs)
{
    (void)rhs;
    return(*this);
}

AForm* Intern::shrubberyCreationForm(const std::string target) const
{
    return(new ShrubberyCreationForm(target));
}

AForm* Intern::robotomyRequestForm(const std::string target) const
{
    return(new RobotomyRequestForm(target));
}

AForm* Intern::presidentialPardonForm(const std::string target) const
{
    return(new PresidentialPardonForm(target));
}

AForm* Intern::invalidForm(const std::string target) const {
  (void)target;
  return (NULL);
}


AForm* Intern::makeForm(const std::string name, const std::string target) {
  std::string formType[4] = {"shrubbery creation",
                             "robotomy request",
                             "presidential pardon",
                             "invalid form"};
  AForm* (Intern::*f[4])(const std::string) const = {
      &Intern::shrubberyCreationForm,
      &Intern::robotomyRequestForm,
      &Intern::presidentialPardonForm,
      &Intern::invalidForm};

  for (int i = 0; i < 3; i++) {
    if (!formType[i].compare(name)) {
      return ((this->*f[i])(target));
    }
  }
  return ((this->*f[4])(target));
}