/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:56:35 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 12:56:37 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Form.hpp"

class Form;

class Bureaucrat
{
    public:
        Bureaucrat(void);
        Bureaucrat(const std::string name, const int grade);
        Bureaucrat(const Bureaucrat &src);
        ~Bureaucrat(void);

        Bureaucrat &operator=(Bureaucrat const &rhs);

        const std::string &getName(void) const;
        int getGrade(void) const;
        void incrementGrade(void);
        void decrementGrade(void);

        void signForm(const Form &f) const;

        class GradeTooHighException : public std::exception
        {
          public:
            const char* what(void) const throw();
        };
    
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what(void) const throw();
        };

    private:
        const std::string _name;
        int _grade;

};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &in);

#endif
