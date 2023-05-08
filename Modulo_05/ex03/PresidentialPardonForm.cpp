/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:34:45 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/05 22:22:45 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("Presidential Pardon Form ", 25, 5)
{
    std::cout << "[PresidentialPardonForm:: Constructor called]\n";
    return;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: AForm("Presidential Pardon", 25, 5), _target(target)
{
    std::cout << "[PresidentialPardonForm:: Constructor Parametric called]\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
    : AForm(src), _target(src._target)
{
    std::cout << "[PresidentialPardonForm:: Copy Constructor called]\n";
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "[PresidentialPardonForm:: Destructor called]\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    AForm   *tmp1 = this;
    AForm   *tmp2 = const_cast<PresidentialPardonForm*>(&rhs);

    *tmp1 = *tmp2;
    this->_target = rhs._target;
    return (*this);
}

// const std::string &PresidentialPardonForm::getTarget(void) const
// {
//     return (this->_target);
// }

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!this->getSigned())
        throw GradeTooLowException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
    std::cout << executor.getName() << " executed " <<this->getName() << "\n";
}

AForm *PresidentialPardonForm::clone(const std::string &target) const
{
    return(new PresidentialPardonForm(target));
}