/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:25:30 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/05 22:02:07 by joeduard         ###   ########.fr       */
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
        PresidentialPardonForm(const PresidentialPardonForm&);
        virtual ~PresidentialPardonForm(void);

        PresidentialPardonForm &operator=(const PresidentialPardonForm&);

     //   const std::string &getTarget(void) const;

        void    execute(const Bureaucrat &executor) const;
        AForm*   clone(const std::string &target) const;
        
    private:
    std::string      _target;
};

#endif