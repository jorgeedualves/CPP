/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:57:27 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 12:57:29 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm(void);
        AForm(const std::string name, const int gradeSign, const int gradeExec);
        AForm(const AForm &src);
        virtual ~AForm(void);

        AForm				&operator=(const AForm &rhs);

        const std::string	&getName(void) const;
        bool 				getIsFormSigned(void) const;
        int 				getGradeToSign(void) const;
        int 				getGradeToExecute(void) const;

        virtual const std::string	&getTarget(void) const;
        void						setTarget(const std::string &Target);

        void				beSigned(const Bureaucrat &brct);

        virtual void		execute(Bureaucrat const &executor) const = 0;            

        class GradeTooHighException : public std::exception
        {
          public:
            const char*		what(void) const throw();
        };
    
        class GradeTooLowException : public std::exception
        {
            public:
                const char*	what(void) const throw();
        };

        class FileOutuptException: public std::exception
        {
            const char*		what(void) const throw();
        };

        class UnsignedFormException : public std::exception
        {
            const char*		what(void) const throw();
        };

    protected:
        std::string	_target;

    private:
        const std::string	_name;
        bool 				_isFormSigned;
        const int 			_gradeToSign;
        const int 			_gradeToExecute;
};

std::ostream& operator<<(std::ostream& out, const AForm& in);

#endif
