/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:54:30 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/27 18:51:15 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
    public:
        Bureaucrat(void);
        Bureaucrat(const std::string name, const int grade);
        Bureaucrat(const Bureaucrat &src);
        ~Bureaucrat(void);

        Bureaucrat &operator=(Bureaucrat const &rhs);

        const std::string &getName(void) const;
        int getGrade(void) const;
        void incrementGrade(void);
        void decrementGrade(void);

        class GradeTooHighException : public std::exception
        {
          public:
            const char* what(void) const throw();
        };
    
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what(void) const throw();
        };

    private:
        std::string _name;
        int _grade;

};

std::ostream &operator<<(std::ostream &out, Bureaucrat &in);


#endif