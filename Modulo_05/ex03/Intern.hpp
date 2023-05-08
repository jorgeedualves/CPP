/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:44:06 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/05 19:34:56 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern(void);
        Intern(const Intern&);
        virtual ~Intern(void);
        
        Intern &operator=(const Intern& rhs);

        AForm* makeForm(const std::string& FormName, const std::string& target)const;
    private:
        AForm  *_forms[3];
};

#endif



