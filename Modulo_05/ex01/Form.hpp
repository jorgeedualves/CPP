/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:56:51 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 12:56:57 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form(void);
        Form(const std::string name, const int gradeSing, const int gradeExec);
        Form(const Form &src);
        ~Form(void);

        Form &operator=(const Form &rhs);

        const std::string &getName(void) const;
        bool getSigned(void) const;
        int getGradeSign(void) const;
        int getGradeExecute(void) const;

        void beSigned(const Bureaucrat &brct);            

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
        bool _isFormSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
};

std::ostream& operator<<(std::ostream& out, const Form& in);

#endif
