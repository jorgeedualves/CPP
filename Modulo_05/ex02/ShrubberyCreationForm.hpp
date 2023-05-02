/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:45:59 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/02 17:10:12 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

#define TREE " *      \n\
              *o*     \n\
             *o*o*    \n\
            *o***o*   \n\
           *o*****o*  \n\
          **o*****o** \n\
               ||     \n\
             ======   \n" 
            
class ShrubberyCreationForm : public AForm
{
    public:
    ShrubberyCreationForm(void);
    explicit ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &src);
    virtual ~ShrubberyCreationForm(void);

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

    const std::string &getTarget(void) const;

    void execute(const Bureaucrat &exe) const;
};

#endif