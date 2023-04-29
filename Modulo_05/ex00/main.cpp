/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:15:56 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/28 14:21:01 by joeduard         ###   ########.fr       */
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
        std::cout << "**catch Raquel**\n";
        std::cerr << exc.what() << std::endl;
    }

    try
    {
        bureaucrat = new Bureaucrat("Rafaela", 1);
        std::cout << "Bureaucrat : "<< *bureaucrat << "\nGrade: " << bureaucrat->getGrade() << "\n";
        bureaucrat->incrementGrade();
        delete bureaucrat;    
    }
    catch (std::exception & exc)
    {
        std::cout << "**catch Rafaela**\n";
        std::cerr << exc.what() << std::endl;
    }

    try
    {
        bureaucrat = new Bureaucrat("Rosana", 150);
        std::cout << "Bureaucrat : "<< *bureaucrat << "\nGrade: " << bureaucrat->getGrade() << "\n";
        bureaucrat->decrementGrade();
        delete bureaucrat;    
    }
    catch (std::exception & exc)
    {
        std::cout << "**catch Rosana**\n";
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
        std::cout << "**catch Rita**\n";
        std::cerr << exc.what() << std::endl;
    }
    
    return (0);
}