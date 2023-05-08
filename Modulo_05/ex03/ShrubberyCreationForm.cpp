/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:04:37 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/05 22:59:43 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm ("Shrubbery Creation Form\n ", 145, 137)
{
    std::cout << "[ShrubberyCreationFor:: Constructor called]\n";
    return;
}
    
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm ("Shrubbery Creation Form\n ", 145, 137), _target(target)
{
    std::cout << "[ShrubberyCreationFor:: Constructor Parametric called]\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
: AForm(src), _target(src._target)
{
    std::cout << "[ShrubberyCreationFor:: Copy Constructor called]\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "[ShrubberyCreationFor:: Destructor called]\n";
    return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    std::cout << "[ShrubberyCreationFor:: assignment operator called]\n";
    AForm   *tmp1 = this;
    AForm   *tmp2 = const_cast<ShrubberyCreationForm*>(&rhs);

    *tmp1 = *tmp2;
    this->_target = rhs._target; 
    return (*this);
}

// const std::string &ShrubberyCreationForm::getTarget(void) const
// {
//     return (this->_target);          
// }

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!this->getSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
   
    std::string fileOutput(_target + "_shrubbery");
    
    std::ofstream ofs(fileOutput.c_str());
    if(ofs.fail())
    {
        throw AForm::FileOutuptException();
    }
    std::string tree =
        "       *      \n"
        "      *o*     \n"
        "     *o*o*    \n"
        "    *o***o*   \n"
        "   *o*****o*  \n"
        "  *o*******o* \n"
        "       ||     \n"
        "     ======   \n"; 
        ofs << tree;
        ofs.close();
}

AForm *ShrubberyCreationForm::clone(const std::string &target) const
{
    return (new ShrubberyCreationForm(target));
}

