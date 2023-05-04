/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:25:30 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/02 23:34:25 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(void);
        explicit PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &src);
        virtual ~PresidentialPardonForm(void);

        PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

        const std::string &getTarget(void) const;

        void execute(const Bureaucrat &executor) const;
};

#endif