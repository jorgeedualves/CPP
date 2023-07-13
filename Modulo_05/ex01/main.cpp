/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:57:03 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 12:57:04 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat *bureaucrat;
    Form *form;

    std::cout << "\n";
	std::cout << "TESTING FORM: \n" << std::endl;
	
	std::cout << "Test 1: too high " << std::endl;
	try
	{
		form = new Form("Form1", -1, 1);
    	std::cout << *form;
    	delete form;
  	} 
	catch (std::exception& e)
	{
		std::cout << "Form 1\n";
    	std::cerr << e.what() << "\n";
  	}

    std::cout << "\n";

	std::cout << "Test 2: too low " << std::endl;
  	try
	{
    	form = new Form("Form2", 151, 1);
    	std::cout << *form;
    	delete form;
  	}
	catch (std::exception& e)
	{
		std::cout << "Form 2\n";
    	std::cerr << e.what() << "\n";
  	}


    std::cout <<"\n";
	std::cout << "\nTESTING GRADES TO SIGN FORMS:" << std::endl;
    std::cout <<"\nTEST 1: Grade OK\n";

    try
    {
        bureaucrat = new Bureaucrat("Joao", 1);
        form = new Form("Form 3", 1, 1);
        bureaucrat->signForm(*form);
        delete bureaucrat;
        delete form;    
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout <<"\n";

    std::cout <<"\nTEST 2: Grade too low\n";
    try
    {
        bureaucrat = new Bureaucrat("Roberto", 2);
        form = new Form("Form 4", 1, 1);
        bureaucrat->signForm(*form);
        delete bureaucrat;
        delete form;    
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout <<"\n";

    std::cout <<"\nTEST 3: Grade to sign OK, grade to execute too high\n";
    try
    {
        bureaucrat = new Bureaucrat("Roberto", 2);
        form = new Form("Form 4", 2, -1);
        bureaucrat->signForm(*form);
        delete bureaucrat;
        delete form;    
    }
    catch (std::exception & e)
    {
		delete bureaucrat;
        std::cerr << e.what() << std::endl;
    }
    std::cout <<"\n";

    std::cout <<"\nTEST 4: Grade to sign OK, grade to execute too low\n";
    try
    {
        bureaucrat = new Bureaucrat("Roberto", 2);
        form = new Form("Form 4", 2, 151);
        bureaucrat->signForm(*form);
        delete bureaucrat;
        delete form;    
    }
    catch (std::exception & e)
    {
		delete bureaucrat;
        std::cerr << e.what() << std::endl;
    }
    std::cout <<"\n";


    return (0);
}
