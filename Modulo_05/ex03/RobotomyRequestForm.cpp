/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:53:44 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/05 22:43:17 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request Form", 72, 45)
{
	std::cout << "[RobotomyRequestForm::] Constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm("Robotomy Request Form", 72, 45), _target(target)
{
    std::cout << "[RobotomyRequestForm:: Constructor Parametric called]\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src), _target(src._target)
{
    std::cout << "[RobotomyRequestForm:: Copy Constructor called]\n";
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "[RobotomyRequestForm:: Destructor called]\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    AForm   *temp1 = this;
    AForm   *temp2 = const_cast<RobotomyRequestForm*>(&rhs);

    *temp1 = *temp2;
    this->_target = rhs._target;
    return (*this);
}

// const std::string &RobotomyRequestForm::getTarget(void) const
// {
//     return (this->_target);
// }

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!this->getSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << executor.getName() << " executed " << this->getName() << "\n";
    srand(time(NULL));
    std::cout << "TrUtRuTrU\n";
    if (rand() & 1)
        std::cout << _target << " has been robotomized successfully\n";
    else
        std::cout << _target << " failed to be robotomized\n";    
}


AForm* RobotomyRequestForm::clone(const std::string &target) const
{
    return(new RobotomyRequestForm(target));
}
