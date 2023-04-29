/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:14:35 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/28 22:28:16 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

 Form::Form(void) : _name(""), _signed(false), _gradeSign(0), _gradeExecute(0) 
 {
    std::cout << "[Form::] Constructor called\n";
    return;
 }

Form::Form(const std::string name, const int gradeSing, const int gradeExec) : _name(name), _signed(false),
                                                                               _gradeSign(gradeSing),
                                                                               _gradeExecute(gradeExec)
{
    std::cout << "[Form::] Constructor Parametric called\n";
    if (this->_gradeSign < 1)
        throw GradeTooHighException();
    if (this->_gradeSign > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &src) :_name(""), _signed(false), _gradeSign(0), _gradeExecute(0)
{
    std::cout << "[Form::] Copy Constructor called\n";
    *this = src;
    if (src.getGradeSign() < 1)
        throw GradeTooHighException();
    if (src.getGradeSign() > 150)
        throw GradeTooLowException();
}

Form::~Form(void)
{
    std::cout << "[Form::] Destructor called\n";
    return;
}

Form &Form::operator=(const Form &rhs)
{
    std::cout << "[Form::] assignment operator called\n";
    const_cast<std::string&>(this->_name) = rhs.getName();
    this->_signed = rhs.getGradeSign();
    const_cast<int&>(this->_gradeSign) = rhs.getGradeSign();
    const_cast<int&>(this->_gradeExecute) = rhs.getGradeExecute(); 
    return(*this);
}

const std::string &Form::getName(void) const
{
    return (this->_name);
}

bool Form::getSigned(void) const
{
    return (this->_signed);
}

int Form::getGradeSign(void) const
{
    return(this->_gradeSign);
}

int Form::getGradeExecute(void) const
{
    return (this->_gradeExecute);
}

void Form::beSigned(const Bureaucrat &brct)
{
    if (brct.getGrade() <= this->_gradeSign)
        this->_signed = true;
    if (brct.getGrade() > this->_gradeSign)
        throw Form::GradeTooHighException();
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
    out << in.getName();
	return (out);
}
