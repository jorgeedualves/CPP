/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:51:11 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/03 17:02:28 by joeduard         ###   ########.fr       */
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
    b = new Bureaucrat("Bob", 1);            // Bureaucrat::               Constructor Parametric
    f = new ShrubberyCreationForm("Bobbie"); // ShrubberyCreationFor::     Constructor Parametric
    b->signForm(*f);                         // Bureaucrat::               signForm
    std::cout << *f;                         // AForm::                    ostream& operator<<
    b->executeForm(*f);                      // ShrubberyCreationForm::    Constructor Parametric
    delete b;
    delete f;
  } catch (std::exception& e) {
    std::cerr << e.what() << "\n";
  }

  std::cout << "*******************\n";

  try {
    b = new Bureaucrat("Tob", 1);
    f = new RobotomyRequestForm("Tobbie");
    b->signForm(*f);
    std::cout << *f;
    b->executeForm(*f);
    delete b;
    delete f;
  } catch (std::exception& e) {
    std::cerr << e.what() << "\n";
  }

  std::cout << "\n";

  // try {
  //   b = new Bureaucrat("Job", 1);
  //   f = new PresidentialPardonForm("Jobbie");
  //   b->signForm(*f);
  //   std::cout << *f;
  //   b->executeForm(*f);
  //   delete b;
  //   delete f;
  // } catch (std::exception& e) {
  //   std::cerr << e.what() << "\n";
  // }

  // std::cout << "\n";

  // try {
  //   b = new Bureaucrat("Lob", 150);
  //   f = new PresidentialPardonForm("Lobbie");
  //   b->signForm(*f);
  //   std::cout << *f;
  //   b->executeForm(*f);
  //   delete b;
  //   delete f;
  // } catch (std::exception& e) {
  //   std::cerr << e.what() << "\n";
  // }

  // std::cout << "\n";

  // try {
  //   b = new Bureaucrat("Pob", 20);
  //   f = new PresidentialPardonForm("Pobbie");
  //   std::cout << *b;
  //   b->signForm(*f);
  //   std::cout << *f;
  //   b->executeForm(*f);
  //   delete b;
  //   delete f;
  // } catch (std::exception& e) {
  //   std::cerr << e.what() << "\n";
  // }

  std::cout << "\n";

  return (0);
}
