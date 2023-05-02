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

 AForm::AForm(void) : _name(""), _signed(false), _gradeSign(0), _gradeExecute(0) 
 {
    std::cout << "[AForm::] Constructor called\n";
    return;
 }

AForm::AForm(const std::string name, const int gradeSing, const int gradeExec) : _name(name), _signed(false),
                                                                               _gradeSign(gradeSing),
                                                                               _gradeExecute(gradeExec)
{
    std::cout << "[AForm::] Constructor Parametric called\n";
    if (this->_gradeSign < 1)
        throw GradeTooHighException();
    if (this->_gradeSign > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &src) :_name(""), _signed(false), _gradeSign(0), _gradeExecute(0)
{
    std::cout << "[AForm::] Copy Constructor called\n";
    *this = src;
    if (src.getGradeSign() < 1)
        throw GradeTooHighException();
    if (src.getGradeSign() > 150)
        throw GradeTooLowException();
}

AForm::~AForm(void)
{
    std::cout << "[AForm::] Destructor called\n";
    return;
}

AForm &AForm::operator=(const AForm &rhs)
{
    std::cout << "[AForm::] assignment operator called\n";
    const_cast<std::string&>(this->_name) = rhs.getName();
    this->_signed = rhs.getGradeSign();
    const_cast<int&>(this->_gradeSign) = rhs.getGradeSign();
    const_cast<int&>(this->_gradeExecute) = rhs.getGradeExecute(); 
    return(*this);
}

const std::string &AForm::getName(void) const
{
    return (this->_name);
}

bool AForm::getSigned(void) const
{
    return (this->_signed);
}

int AForm::getGradeSign(void) const
{
    return(this->_gradeSign);
}

int AForm::getGradeExecute(void) const
{
    return (this->_gradeExecute);
}

void AForm::setTarget(const std::string &target)
{
    const_cast<std::string&>(this->_target) = target;
}

void AForm::beSigned(const Bureaucrat &brct)
{
    if (brct.getGrade() <= this->_gradeSign)
        this->_signed = true;
    if (brct.getGrade() > this->_gradeSign)
        throw AForm::GradeTooHighException();
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
     return("AForm required Grade Invalid: to high");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
     return("AForm required Grade Invalid: to low");
}

const char* AForm::FileOutuptException::what(void) const throw()
{
    return("Cannot write the file output!");
}

const char* AForm::UnsignedFormException::what(void) const throw()
{
    return ("Form is not signed!");
}

std::ostream& operator<<(std::ostream& out, const AForm& in)
{
    out << in.getName();
	return (out);
}
