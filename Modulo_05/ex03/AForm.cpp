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

 AForm::AForm(void) : _name("Default"), _gradeToSign(100), _gradeToExecute(100) 
 {
    std::cout << "[AForm:: Constructor called]\n";
    this->_isFormSigned = false;
 }

AForm::AForm(const std::string name, const int gradeSing, const int gradeExec)
: _name(name), _gradeToSign(gradeSing),_gradeToExecute(gradeExec)
{
    std::cout << "[AForm:: Constructor Parametric called]\n";
    if (this->_gradeToSign < 1)
        throw GradeTooHighException();
    if (this->_gradeToSign > 150)
        throw GradeTooLowException();
    this->_isFormSigned = false;
}

AForm::AForm(const AForm &src) 
    :_name(src._name), _isFormSigned(src._isFormSigned),
    _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "[AForm:: Copy Constructor called]\n";
    *this = src;
    if (_gradeToSign < 1 || _gradeToSign < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::~AForm(void)
{
    std::cout << "[AForm:: Destructor called]\n";
}

AForm& AForm::operator=(const AForm& rhs)
{
    std::cout << "[AForm:: assignment operator called]\n";
    const_cast<std::string&>(this->_name) = rhs._name;
    this->_isFormSigned = rhs._isFormSigned;
    const_cast<int&>(this->_gradeToSign) = rhs._gradeToSign;
    const_cast<int&>(this->_gradeToExecute) = rhs._gradeToExecute; 
    return(*this);
}

const std::string& AForm::getName(void) const
{
    return (_name);
}

bool AForm::getSigned(void) const
{
    return (_isFormSigned);
}

int AForm::getGradeToSign(void) const
{
    return(_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
    return (_gradeToExecute);
}

// const std::string &AForm::getTarget(void) const
// {
//     return (this->_target);
// }

// void AForm::setTarget(const std::string &target)
// {
//     const_cast<std::string&>(this->_target) = target;
// }

void AForm::beSigned(const Bureaucrat &brct)
{   
    if (brct.getGrade() > _gradeToSign)
        throw GradeTooHighException();
    if (_isFormSigned)
        throw GradeTooHighException();
    _isFormSigned = true;
    std::cout << brct.getName() << " signed " << this->_name <<"\n";
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

// std::ostream& operator<<(std::ostream& cout, const AForm& form)
// {   cout << "\n\t** Form Information: **\n";
//     cout << "Form Name:\t\t" << form.getName() << "\n";
//     // cout << "Target:\t\t\t" << form.getTarget() << "\n";
//     cout << "Is Signed: \t\t" << (form.getSigned() ? "yes" : "no") <<"\n";
//     cout << "Grade to sing: \t\t" << form.getGradeToSign() << "\n";
//     cout << "Grade to execute:\t" << form.getGradeToExecute() << "\n\n";

// 	return (cout);
// }
