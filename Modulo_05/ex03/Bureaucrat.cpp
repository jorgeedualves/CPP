/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:57:25 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/05 19:32:05 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Form"), _grade(75)
{
    std::cout << "[Bureaucrat:: Constructor called]\n";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name)
{
    std::cout << "[Bureaucrat:: Constructor Parametric called]\n";
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
    : _name(src._name)
{
    std::cout << "\n[Bureaucrat:: Copy Constructor called]\n";
    *this = src;
    if (src.getGrade() < 1)
        throw GradeTooHighException();
    if (src.getGrade() > 150)
        throw GradeTooLowException();
    _grade = src._grade;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "[Bureaucrat:: Destructor called]\n";
    return;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    std::cout << "[Bureaucrat:: assignment operator called]\n";
    this->_grade = rhs._grade;
    const_cast<std::string&>(this->_name) = rhs._name;
    return(*this);
}

Bureaucrat Bureaucrat::operator++(int) {
    if (_grade - 1 <= 0) {
        throw GradeTooHighException();
    }
    Bureaucrat  tmp(_name, _grade);
    _grade--;
    return (tmp);
}

Bureaucrat& Bureaucrat::operator++(void) {
    if (_grade - 1 <= 0) {
        throw GradeTooHighException();
    }
    _grade--;
    return (*this);
}

std::string	Bureaucrat::getName(void) const
{
    return (_name);
}

int Bureaucrat::getGrade(void) const
{
    std::cout << "getGrade" << "\n";
    return (_grade);
}

// void Bureaucrat::incrementGrade(void)
// {
//     if ((this->_grade - 1) < 1)
//         throw GradeTooHighException();
//     else
//         this->_grade--;
// }

// void Bureaucrat::decrementGrade(void)
// {
//     if ((this->_grade + 1 > 150))
//         throw GradeTooLowException();
//     else
//         this->_grade++;
// }

void Bureaucrat::signForm(AForm* form)
{
    try
    {   
        std::cout << "\n[Bureaucrat::signForm]\n";
        form->beSigned(*this);
    }
    catch(const std::exception& exc)
    {
        std::cout << _name << " couldn't sing: " << form->getName()
		<< " : "<< exc.what() << "\n";
		return;
    } 
}

void Bureaucrat::executeForm(const AForm& form) const
{
    std::cout << "[Bureaucrat:: executeForm]" << "\n";
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << "\n";
    }
    catch(const std::exception &exc)
    {
        std::cout << this->getName() << " couldn't execute " << form.getName()
		<< " : " << exc.what() << "\n";
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