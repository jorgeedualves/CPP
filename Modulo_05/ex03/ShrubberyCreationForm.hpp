/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:45:59 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/05 22:44:09 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
            
class ShrubberyCreationForm : public AForm
{
    public:
      ShrubberyCreationForm(void);
      explicit ShrubberyCreationForm(const std::string &target);
      ShrubberyCreationForm(const ShrubberyCreationForm&);
      virtual ~ShrubberyCreationForm(void);

      ShrubberyCreationForm &operator=(const ShrubberyCreationForm&);

      const std::string &getTarget(void) const;

      void execute(const Bureaucrat &exe) const;
      AForm *clone(const std::string &target) const;

    private:
    std::string      _target;
};

#endif