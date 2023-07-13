/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:56:42 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 12:56:45 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

 Form::Form(void) : _name(""), _isFormSigned(false), _gradeToSign(0), _gradeToExecute(0) 
 {
    return;
 }

Form::Form(const std::string name, const int gradeSign, const int gradeExec)
    : _name(name), _isFormSigned(false), _gradeToSign(gradeSign), _gradeToExecute(gradeExec)
{
    if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
        throw GradeTooHighException();
    if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &src) :_name(""), _isFormSigned(false), _gradeToSign(0), _gradeToExecute(0)
{
    *this = src;
    if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
        throw GradeTooHighException();
    if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::~Form(void)
{
    return;
}

Form &Form::operator=(const Form &rhs)
{
    const_cast<std::string&>(this->_name) = rhs.getName();
    this->_isFormSigned = rhs.getGradeSign();
    const_cast<int&>(this->_gradeToSign) = rhs.getGradeSign();
    const_cast<int&>(this->_gradeToExecute) = rhs.getGradeExecute(); 
    return(*this);
}

const std::string &Form::getName(void) const
{
    return (this->_name);
}

bool Form::getSigned(void) const
{
    return (this->_isFormSigned);
}

int Form::getGradeSign(void) const
{
    return(this->_gradeToSign);
}

int Form::getGradeExecute(void) const
{
    return (this->_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &brct)
{
    if (brct.getGrade() <= this->_gradeToSign)
        this->_isFormSigned = true;
    if (brct.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what(void) const throw()
{
     return("Form required Grade Invalid: to high");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
     return("Form required Grade Invalid: to low");
}

std::ostream& operator<<(std::ostream& out, const Form& in)
{
	out << "Form: " << in.getName() << "\n";
  	out << "Signed: " << (in.getSigned() ? "Yes" : "No") << "\n";
  	out << "Grade to sign: " << in.getGradeSign() << "\n";
  	out << "Grade to exec: " << in.getGradeExecute() << "\n";

	return (out);
}
