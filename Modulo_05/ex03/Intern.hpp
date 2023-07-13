/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:41:01 by azamario          #+#    #+#             */
/*   Updated: 2023/07/13 13:05:41 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <exception>
#include <string>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{	
  public:
	Intern(void);
    Intern(const Intern &src);
    ~Intern(void);

    Intern& operator=(const Intern& rhs);
	
	AForm*		makePresidentialPardonForm(const std::string target) const;
    AForm*		makeRobotomyRequestForm(const std::string target) const;
    AForm*		makeShrubberyCreationForm(const std::string target) const;
	AForm*		invalidForm(const std::string target) const;

    AForm		*makeForm(const std::string name, const std::string target);

  	class NoMatchException : public std::exception
	{
		public:
    		const char*		what(void) const throw();
  	};
};

#endif
