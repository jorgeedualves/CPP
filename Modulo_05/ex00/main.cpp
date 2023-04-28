/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:15:56 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/28 11:00:22 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat *bureaucrat;

    try
    {
        bureaucrat = new Bureaucrat("Joao 1", 1);
        std::cout << "Bureaucrat : "<< *bureaucrat << "\nGrade: " << bureaucrat->getGrade() << "\n";
        delete bureaucrat;    
    }
    catch (std::exception & exc)
    {
        std::cerr << exc.what() << std::endl;
    }

     try
    {
        bureaucrat = new Bureaucrat("Joao 2", 3);
        bureaucrat->incrementGrade();
        std::cout << "Bureaucrat : "<< *bureaucrat << "\nGrade: " << bureaucrat->getGrade() << "\n";
        delete bureaucrat;    
    }
    catch (std::exception & exc)
    {
        std::cerr << exc.what() << std::endl;
    }

     try
    {
        bureaucrat = new Bureaucrat("Joao 3", 2);
        bureaucrat->decrementGrade();
        std::cout << "Bureaucrat : "<< *bureaucrat << "\nGrade: " << bureaucrat->getGrade() << "\n";
        delete bureaucrat;    
    }
    catch (std::exception & exc)
    {
        std::cerr << exc.what() << std::endl;
    }

    try
    {
        bureaucrat = new Bureaucrat("Raquel", -1);
        std::cout << "Bureaucrat : "<< *bureaucrat << "\nGrade: " << bureaucrat->getGrade() << "\n";
        delete bureaucrat;    
    }
    catch (std::exception & exc)
    {
        std::cerr << exc.what() << std::endl;
    }

    try
    {
        bureaucrat = new Bureaucrat("Rafaela", 1);
        bureaucrat->incrementGrade();
        std::cout << "Bureaucrat : "<< *bureaucrat << "\nGrade: " << bureaucrat->getGrade() << "\n";
        delete bureaucrat;    
    }
    catch (std::exception & exc)
    {
        std::cerr << exc.what() << std::endl;
    }

    try
    {
        bureaucrat = new Bureaucrat("Rosana", 150);
        bureaucrat->decrementGrade();
        std::cout << "Bureaucrat : "<< *bureaucrat << "\nGrade: " << bureaucrat->getGrade() << "\n";
        delete bureaucrat;    
    }
    catch (std::exception & exc)
    {
        std::cerr << exc.what() << std::endl;
    }

     try
    {
        bureaucrat = new Bureaucrat("Rita", 151);
        std::cout << "Bureaucrat : "<< *bureaucrat << "\nGrade: " << bureaucrat->getGrade() << "\n";
        delete bureaucrat;    
    }
    catch (std::exception & exc)
    {
        std::cerr << exc.what() << std::endl;
    }
    
    return (0);
}