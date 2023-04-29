/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:14:39 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/28 20:18:35 by joeduard         ###   ########.fr       */
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
        bool _signed;
        const int _gradeSign;
        const int _gradeExecute;
};

std::ostream& operator<<(std::ostream& out, const Form& in);

#endif