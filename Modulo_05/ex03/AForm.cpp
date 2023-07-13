/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:00:09 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 13:00:11 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

 AForm::AForm(void) : _target(""), _name(""), _isFormSigned(false), _gradeToSign(0), _gradeToExecute(0) 
 {
    return;
 }

AForm::AForm(const std::string name, const int gradeSign, const int gradeExec) 
    : _target(""), _name(name), _isFormSigned(false), _gradeToSign(gradeSign), _gradeToExecute(gradeExec)
{
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
	{
    	throw GradeTooHighException();
  	}
  	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
	{
    	throw GradeTooLowException();
  	}
}

AForm::AForm(const AForm &src) :_target(""), _name(""), _isFormSigned(false), _gradeToSign(0), _gradeToExecute(0)
{
    *this = src;
  	if (src.getGradeToSign() < 1 || src.getGradeToExecute() < 1)
	{
    	throw GradeTooHighException();
  	}
  	if (src.getGradeToSign() > 150 || src.getGradeToExecute() > 150)
	{
    	throw GradeTooLowException();
  	}
}

AForm::~AForm(void)
{
    return;
}

AForm &AForm::operator=(const AForm &rhs)
{
    const_cast<std::string&>(this->_target) = rhs.getTarget();
    const_cast<std::string&>(this->_name) = rhs.getName();
    this->_isFormSigned = rhs.getIsFormSigned();
    const_cast<int&>(this->_gradeToSign) = rhs.getGradeToSign();
    const_cast<int&>(this->_gradeToExecute) = rhs.getGradeToExecute(); 
    return(*this);
}

const std::string &AForm::getName(void) const
{
    return (this->_name);
}

bool AForm::getIsFormSigned(void) const
{
    return (this->_isFormSigned);
}

int AForm::getGradeToSign(void) const
{
    return(this->_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
    return (this->_gradeToExecute);
}

const std::string &AForm::getTarget(void) const
{
    return (this->_target);
}

void AForm::setTarget(const std::string &target)
{
    const_cast<std::string&>(this->_target) = target;
}

void AForm::beSigned(const Bureaucrat &brct)
{
    if (brct.getGrade() <= this->_gradeToSign)
        this->_isFormSigned = true;
    if (brct.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
     return("Form required Grade Invalid: to high\n");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
     return("Form required Grade Invalid: to low\n");
}

const char* AForm::FileOutuptException::what(void) const throw()
{
    return("Cannot write the file output!\n");
}

const char* AForm::UnsignedFormException::what(void) const throw()
{
    return ("Form is not signed!\n");
}

std::ostream& operator<<(std::ostream& cout, const AForm& form)
{   
	cout << "\n\t** Form Information: **\n";
    cout << "Form Name:\t\t" << form.getName() << "\n";
    cout << "Target:\t\t\t" << form.getTarget() << "\n";
    cout << "Is Signed: \t\t" << (form.getIsFormSigned() ? "yes" : "no") <<"\n";
    cout << "Grade to sign: \t\t" << form.getGradeToSign() << "\n";
    cout << "Grade to execute:\t" << form.getGradeToExecute() << "\n\n";

	return (cout);
}
