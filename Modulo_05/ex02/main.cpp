/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:51:11 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/04 11:23:15 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  Bureaucrat* b;
  AForm* f;

  std::cout << "\n";

  try {
    b = new Bureaucrat("Maria", 1);            
    f = new ShrubberyCreationForm("Maria-tree"); 
    b->signForm(*f);                        
    std::cout << *f;                         
    b->executeForm(*f);           
    delete b;
    delete f;
  } catch (std::exception& e) {
    std::cerr << e.what() << "\n";
  }

  std::cout << "****************************************\n";

  try {
    b = new Bureaucrat("Joao", 1);
    f = new RobotomyRequestForm("RobJoao");
    b->signForm(*f);
    std::cout << *f;
    b->executeForm(*f);
    delete b;
    delete f;
  } catch (std::exception& e) {
    std::cerr << e.what() << "\n";
  }

  std::cout << "*******************\n";

  try {  //FALTANDO !!!
    b = new Bureaucrat("Jose", 1);
    f = new PresidentialPardonForm("Presid. Jose");
    b->signForm(*f);
    std::cout << *f;
    b->executeForm(*f);
    delete b;
    delete f;
  } catch (std::exception& e) {
    std::cerr << e.what() << "\n";    
  }

  std::cout << "*******************\n";

  try {
    b = new Bureaucrat("Carlos", 150);
    f = new PresidentialPardonForm("Presid.Carlos");
    b->signForm(*f);
    std::cout << *f;
    b->executeForm(*f);
    delete b;
    delete f;
  } catch (std::exception& e) {
    std::cerr << e.what() << "\n";
  }

  std::cout << "*******************\n";

  try {
    b = new Bureaucrat("Jorge", 10);
    f = new PresidentialPardonForm("Jr");
    std::cout << *b;
    b->signForm(*f);
    std::cout << *f;
    b->executeForm(*f);
    delete b;
    delete f;
  } catch (std::exception& e) {
    std::cerr << e.what() << "\n";
  }

  std::cout << "\n";

  return (0);
}
