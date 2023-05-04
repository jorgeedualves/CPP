/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:14:35 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/28 22:28:16 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

 AForm::AForm(void) : _name(""), _isFormSigned(false), _gradeToSign(0), _gradeToExecute(0) 
 {
    std::cout << "[AForm:: Constructor called]\n";
    return;
 }

AForm::AForm(const std::string name, const int gradeSing, const int gradeExec) : _name(name), _isFormSigned(false),
                                                                               _gradeToSign(gradeSing),
                                                                               _gradeToExecute(gradeExec)
{
    std::cout << "[AForm:: Constructor Parametric called]\n";
    if (this->_gradeToSign < 1)
        throw GradeTooHighException();
    if (this->_gradeToSign > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &src) :_name(""), _isFormSigned(false), _gradeToSign(0), _gradeToExecute(0)
{
    std::cout << "[AForm:: Copy Constructor called]\n";
    *this = src;
    if (src.getGradeToSign() < 1)
        throw GradeTooHighException();
    if (src.getGradeToSign() > 150)
        throw GradeTooLowException();
}

AForm::~AForm(void)
{
    std::cout << "[AForm:: Destructor called]\n";
    return;
}

AForm &AForm::operator=(const AForm &rhs)
{
    std::cout << "[AForm:: assignment operator called]\n";
    const_cast<std::string&>(this->_name) = rhs.getName();
    this->_isFormSigned = rhs.getGradeToSign();
    const_cast<int&>(this->_gradeToSign) = rhs.getGradeToSign();
    const_cast<int&>(this->_gradeToExecute) = rhs.getGradeToExecute(); 
    return(*this);
}

const std::string &AForm::getName(void) const
{
    return (this->_name);
}

bool AForm::getSigned(void) const
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
        throw AForm::GradeTooHighException();
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
     return("AForm required Grade Invalid: to high\n");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
     return("AForm required Grade Invalid: to low\n");
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
{   cout << "\n**Form information: **\n";
    cout << "Form Name: " << form.getName() << "\n";
    cout << "Is Signed: " << (form.getSigned() ? "yes" : "no") <<"\n";
    cout << "Grade to sing: " << form.getGradeToSign() << "\n";
    cout << "Gradeto execute:" << form.getGradeToExecute() << "\n";

	return (cout);
}
