/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:15:56 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/02 11:07:10 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat *bureaucrat;
    Form *form;

    try
    {
        bureaucrat = new Bureaucrat("Joao 1", 1);
        form = new Form("Form 1", 1, 1);
        bureaucrat->signForm(*form);
        delete bureaucrat;
        delete form;    
    }
    catch (std::exception & exc)
    {
        std::cerr << exc.what() << std::endl;
    }

	std::cout <<"\n";

    try
    {
        bureaucrat = new Bureaucrat("Joao 2", 2);
        form = new Form("Form 2", 1, 1);
        bureaucrat->signForm(*form);
        delete bureaucrat;
        delete form;    
    }
    catch (std::exception & exc)
    {
		std::cout << "**joao 2**\n";
        std::cerr << exc.what() << std::endl;
    }

	std::cout <<"\n";

	 try
    {
        form = new Form("Form 3", -1, 1);
        std::cout << *form;
        delete bureaucrat;
        delete form;    
    }
    catch (std::exception & exc)
    {
		std::cout << "**Form 3**\n";
        std::cerr << exc.what() << std::endl;
    }

	std::cout <<"\n";
	
	try
    {
        form = new Form("Form 4", 151, 1);
		std::cout << *form;
        delete form;    
    }
    catch (std::exception & exc)
    {
		std::cout << "**Form 4**\n";
        std::cerr << exc.what() << std::endl;
    }   
    return (0);
}    
