/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:41:57 by azamario          #+#    #+#             */
/*   Updated: 2023/07/13 13:09:07 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat* b;
  	Intern 		i;
  	AForm* 		f;

  	std::cout << "\n[*TESTE 1*]\n";
  	try
	{
		b = new Bureaucrat("Kátia", 1);
    	f = i.makeForm("Shrubbery Creation Form", "Katy");
    	b->signForm(*f);
    	std::cout << *f;
    	b->executeForm(*f);
    	delete b;
    	delete f;
  	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
  	}

  	std::cout << "\n[*TESTE 2*]\n";
  	try
	{
    	b = new Bureaucrat("João", 1);
    	f = i.makeForm("Robotomy Request Form", "Jhon");
    	b->signForm(*f);
    	std::cout << *f;
    	b->executeForm(*f);
    	delete b;
    	delete f;
  	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
  	}

  	std::cout << "\n[*TESTE 3*]\n";
  	try
	{
    	b = new Bureaucrat("Maria", 1);
    	f = i.makeForm("Presidential Pardon Form", "Mary");
    	b->signForm(*f);
    	std::cout << *f;
    	b->executeForm(*f);
    	delete b;
    	delete f;
  	}
	catch (std::exception& e)
	{
    	std::cerr << e.what() << "\n";
  	}

  	std::cout << "\n[*TESTE 4*]\n";
  	try
	{
		b = new Bureaucrat("Carolina", 150);
    	f = i.makeForm("Crazy Form", "Caroline");
    	b->signForm(*f);
    	std::cout << *f;
    	b->executeForm(*f);
    	delete b;
    	delete f;
  	}
	catch (std::exception& e)
	{
    	std::cerr << e.what() << "\n";
    	delete b;
  	}

  	std::cout << "\n[*TESTE 5*]\n";
  	try
	{
    	b = new Bureaucrat("Marco", 150);
    	f = i.makeForm("Presidential Pardon Form", "Mark");
    	b->signForm(*f);
    	std::cout << *f;
    	b->executeForm(*f);
    	delete b;
    	delete f;
  	}
	catch (std::exception& e)
	{
    	std::cerr << e.what() << "\n";
  	}

  	std::cout << "\n[*TESTE 6*]\n";
  	try
	{
    	b = new Bureaucrat("Bob", 20);
    	f = i.makeForm("Presidential Pardon Form", "Bobbie");
    	b->signForm(*f);
    	std::cout << *f;
    	b->executeForm(*f);
    	delete b;
    	delete f;
  	}
	catch (std::exception& e)
	{
    	std::cerr << e.what() << "\n";
  	}

  	std::cout << "\n";

  	return (0);
}
