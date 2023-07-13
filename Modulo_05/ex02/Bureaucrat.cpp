/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:57:37 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 12:57:39 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name(""), _grade(0)
{
    return;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name), _grade(grade)
{
    if (this->_grade < 1)
        throw GradeTooHighException();
    if (this->_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    *this = src;
    if (src.getGrade() < 1)
        throw GradeTooHighException();
    if (src.getGrade() > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void)
{
    return;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    const_cast<std::string&>(this->_name) = rhs.getName();
	this->_grade = rhs.getGrade();
    return(*this);
}

const std::string &Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
    if ((this->_grade - 1) < 1)
        throw GradeTooHighException();
    else
        this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
    if ((this->_grade + 1) > 150)
        throw GradeTooLowException();
    else
        this->_grade++;
}

void Bureaucrat::signForm(const AForm &form) const
{
    try
    {   
        (*const_cast<AForm*>(&form)).beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << "\n";
    } 
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        (*const_cast<AForm*>(&form)).execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << "\n";
    }
    catch(const std::exception &e)
    {
        std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << "\n";
    } 
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return("[Bureaucrat::] Bureaucrat Grade Invalid: to high\n");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return("[Bureaucrat::] Bureaucrat Grade Invalid: to low\n");
}

std::ostream &operator<<(std::ostream &cout, Bureaucrat const &bureaucrat)
{
	return (cout << bureaucrat.getName() << " | bureaucrat grade: " << bureaucrat.getGrade() << "\n");
}
