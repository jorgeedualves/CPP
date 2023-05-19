/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:39:24 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/08 22:29:12 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  Bureaucrat* b;
  Intern i;
  AForm* f;

  std::cout << "\n";

  try {
    
    b = new Bureaucrat("Bob", 1);
    f = i.makeForm("shrubbery creation", "Bobbie");
    b->signForm(*f);
    std::cout << *f;
    b->executeForm(*f);
    delete b;
    delete f;
  } catch (std::exception& e) {
    std::cerr << e.what() << "\n";
  }

  std::cout << "\n";

  try {
    b = new Bureaucrat("Tob", 1);
    f = i.makeForm("robotomy request", "Tobbie");
    b->signForm(*f);
    std::cout << *f;
    b->executeForm(*f);
    delete b;
    delete f;
  } catch (std::exception& e) {
    std::cerr << e.what() << "\n";
  }

  std::cout << "\n";

  try {
    b = new Bureaucrat("Job", 1);
    f = i.makeForm("robotomy request", "Jobbie");
    b->signForm(*f);
    std::cout << *f;
    b->executeForm(*f);
    delete b;
    delete f;
  } catch (std::exception& e) {
    std::cerr << e.what() << "\n";
  }

  std::cout << "\n";

  try {
    b = new Bureaucrat("Xob", 150);
    f = i.makeForm("invalid form", "Xobbie");
    b->signForm(*f);
    std::cout << *f;
    b->executeForm(*f);
    delete b;
    delete f;
  } catch (std::exception& e) {
    std::cerr << e.what() << "\n";
    delete b;
  }

  std::cout << "\n";

  try {
    b = new Bureaucrat("Lob", 150);
    f = new PresidentialPardonForm("Lobbie");
    b->signForm(*f);
    std::cout << *f;
    b->executeForm(*f);
    delete b;
    delete f;
  } catch (std::exception& e) {
    std::cerr << e.what() << "\n";
  }

  std::cout << "\n";

  try {
    b = new Bureaucrat("Pob", 20);
    f = new PresidentialPardonForm("Pobbie");
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