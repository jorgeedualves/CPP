/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:53:44 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/03 17:38:03 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request Form", 72, 45)
{
	std::cout << "[RobotomyRequestForm::] Constructor called\n";
    return;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy Request Form", 72, 45)
{
    std::cout << "[RobotomyRequestForm:: Constructor Parametric called]\n";
    this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{
    std::cout << "[RobotomyRequestForm:: Copy Constructor called]\n";
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "[RobotomyRequestForm:: Destructor called]\n";
    return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    (void) rhs;
    return (*this);
}

const std::string &RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    unsigned int seed;
    int randNum = rand_r(&seed) % (10);

    if (this->getSigned() == false)
        throw AForm::UnsignedFormException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooHighException();
    else if (executor.getGrade() <= this->getGradeToExecute() && randNum < 5)
    {
        std::cout << "zzzzzzzz\n";
        std::cout << this->getTarget() << " has been robotomized sucessfully\n";
    }
    else if(executor.getGrade() <= this->getGradeToExecute() && randNum >= 5)
    {
        std::cout << "zzzzzzzz\n";
        std::cout << this->getTarget() << " failed to be robotomized\n";
    }
}