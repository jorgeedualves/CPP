/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:57:25 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/04 11:20:15 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name(""), _grade(0)
{
    std::cout << "[Bureaucrat:: Constructor called]\n";
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name), _grade(grade)
{
    std::cout << "[Bureaucrat:: Constructor Parametric called]\n";
    if (this->_grade < 1)
        throw GradeTooHighException();
    if (this->_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    std::cout << "\n[Bureaucrat:: Copy Constructor called]\n";
    *this = src;
    if (src.getGrade() < 1)
        throw GradeTooHighException();
    if (src.getGrade() > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "[Bureaucrat:: Destructor called]\n";
    return;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    std::cout << "[Bureaucrat:: assignment operator called]\n";
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
    if ((this->_grade + 1 > 150))
        throw GradeTooLowException();
    else
        this->_grade++;
}

void Bureaucrat::signForm(const AForm &form) const
{
    try
    {   
        std::cout << "\n[Bureaucrat::signForm]\n";
        (*const_cast<AForm*>(&form)).beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << "\n";
    }
    catch(const std::exception& exc)
    {
        std::cout << this->getName() << " " << exc.what() << "\n";
    } 
}

void Bureaucrat::executeForm(const AForm &form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << "\n";
    }
    catch(const std::exception &exc)
    {
        std::cout << this->getName() << " couldn't execute " << form.getName() << " because "
        << exc.what() << "\n";
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
	return (cout << bureaucrat.getName() << "   | bureaucrat grade: " << bureaucrat.getGrade());
}