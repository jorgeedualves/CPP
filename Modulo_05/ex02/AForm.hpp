/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:14:39 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/28 20:18:35 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm(void);
        AForm(const std::string name, const int gradeSing, const int gradeExec);
        AForm(const AForm &src);
        ~AForm(void);

        AForm &operator=(const AForm &rhs);

        const std::string &getName(void) const;
        bool getSigned(void) const;
        int getGradeSign(void) const;
        int getGradeExecute(void) const;

        virtual const std::string &getTarget(void) const;
        void AForm::setTarget(const std::string &Target);

        void beSigned(const Bureaucrat &brct);

        virtual void execute(const Bureaucrat &executor) const = 0;            

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

        class FileOutuptException: public std::exception
        {
            const char* what(void) const throw();
        };

        class UnsignedFormException : public std::exception
        {
            const char* what(void) const throw();
        };

    protected:
        const std::string _target;

    private:
        const std::string _name;
        bool _signed;
        const int _gradeSign;
        const int _gradeExecute;
};

std::ostream& operator<<(std::ostream& out, const AForm& in);

#endif