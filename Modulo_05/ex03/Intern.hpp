/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:40:55 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/08 22:27:52 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTER_HPP

#include <exception>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
    public:
        Intern(void);
        Intern(const Intern&);
        ~Intern(void);

        Intern& operator=(const Intern&);

        AForm* shrubberyCreationForm(const std::string target) const;
        AForm* robotomyRequestForm(const std::string target) const;
        AForm* presidentialPardonForm(const std::string target) const;
        AForm* invalidForm(const std::string target) const;

     
        AForm* makeForm(const std::string name, const std::string target);
};

#endif