/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:04:37 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/04 11:04:37 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm ("Shrubbery Creation Form\n ", 145, 137)
{
    std::cout << "[ShrubberyCreationFor:: Constructor called]\n";
    return;
}
    
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm ("Shrubbery Creation Form\n ", 145, 137)
{
    std::cout << "[ShrubberyCreationFor:: Constructor Parametric called]\n";   
    this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :AForm(src)
{
    std::cout << "[ShrubberyCreationFor:: Copy Constructor called]\n";
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "[ShrubberyCreationFor:: Destructor called]\n";
    return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    std::cout << "[ShrubberyCreationFor:: assignment operator called]\n";
    (void) rhs;
    return (*this);
}

const std::string &ShrubberyCreationForm::getTarget(void) const
{
    return (this->_target);          
}

void ShrubberyCreationForm::execute(const Bureaucrat &exe) const
{
    if(this->getSigned() == false)
        throw AForm::UnsignedFormException();
    else if (exe.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooHighException();
    else if (exe.getGrade() <= this->getGradeToExecute())
    {
        std::string fileOutput(this->getTarget() + "_shrubbery");
        std::ofstream ofs(fileOutput.c_str());
        if(ofs.fail())
        {
            throw AForm::FileOutuptException();
        }
         std::string tree =
        "       *       \n"
        "      *o*     \n"
        "     *o*o*     \n"
        "    *o***o*   \n"
        "   *o*****o*  \n"
        "  *o*******o* \n"
        "       ||     \n"
        "     ======   \n"; 
        ofs << tree;
        ofs.close();
    }
}
