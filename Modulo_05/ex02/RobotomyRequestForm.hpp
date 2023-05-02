/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:45:50 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/02 17:45:50 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    RobotomyRequestForm(void);
    explicit RobotomyRequestForm(const std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &src);
    virtual ~RobotomyRequestForm(void);

    RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

    const std::string &getTarget(void) const;

    void execute(const Bureaucrat &executor) const;
};


#endif