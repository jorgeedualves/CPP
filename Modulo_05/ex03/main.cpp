/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:51:11 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/05 23:00:58 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
    Bureaucrat  a("Foo", 130);
    Intern      someRandomIntern;
    AForm        *ppForm;
    AForm        *rrForm;
    AForm        *scForm;
    AForm        *form;

    std::cout << "\n\tIntern Creating forms\n\n";
    ppForm = someRandomIntern.makeForm("presidential pardon", "Bob");
    rrForm = someRandomIntern.makeForm("robotomy request", "Arnold");
    scForm = someRandomIntern.makeForm("shrubbery creation", "forest");
    form = someRandomIntern.makeForm("form", "forest");
   (void)form;
    std::cout << "\n\tBureaucrat signing forms\n\n";
    a.signForm(scForm);
    a.executeForm(*scForm);
    std::cout << '\n';
    a.signForm(ppForm);
    std::cout << a << "\n";
    while (ppForm->getGradeToSign() < a.getGrade())
        ++a;
    Bureaucrat  b = a;
    std::cout << b << "\n";
    std::cout << '\n';
    a.signForm(ppForm);
    std::cout << '\n';
    a.executeForm(*ppForm);
    while (ppForm->getGradeToExecute() < a.getGrade())
        ++a;
    std::cout << '\n';
    a.executeForm(*ppForm);
    std::cout << '\n';
    a.signForm(rrForm);
    std::cout << '\n';
    a.executeForm(*rrForm);
    std::cout << '\n';
    delete ppForm;
    delete rrForm;
    delete scForm;
    delete form;
    return (0);
}

// int main(void) {
//   Bureaucrat* b;
//   Intern i;
//   AForm* f;

//   std::cout << "\n";

//   try {
//     b = new Bureaucrat("Bob", 1);
//     f = i.makeForm("shrubbery creation", "Bobbie");
//     b->signForm(*f);
//     std::cout << *f;
//     b->executeForm(*f);
//     delete b;
//     delete f;
//   } catch (std::exception& e) {
//     std::cerr << e.what() << "\n";
//   }

//   std::cout << "\n";

//   try {
//     b = new Bureaucrat("Tob", 1);
//     f = i.makeForm("robotomy request", "Tobbie");
//     b->signForm(*f);
//     std::cout << *f;
//     b->executeForm(*f);
//     delete b;
//     delete f;
//   } catch (std::exception& e) {
//     std::cerr << e.what() << "\n";
//   }

//   std::cout << "\n";

//   try {
//     b = new Bureaucrat("Job", 1);
//     f = i.makeForm("presidential pardon", "Jobbie");
//     b->signForm(*f);
//     std::cout << *f;
//     b->executeForm(*f);
//     delete b;
//     delete f;
//   } catch (std::exception& e) {
//     std::cerr << e.what() << "\n";
//   }

//   std::cout << "\n";

//   try {
//     b = new Bureaucrat("Xob", 150);
//     f = i.makeForm("invalid form", "Xobbie");
//     b->signForm(*f);
//     std::cout << *f;
//     b->executeForm(*f);
//     delete b;
//     delete f;
//   } catch (std::exception& e) {
//     std::cerr << e.what() << "\n";
//     delete b;
//   }

//   std::cout << "\n";

//   try {
//     b = new Bureaucrat("Lob", 150);
//     f = new PresidentialPardonForm("Lobbie");
//     b->signForm(*f);
//     std::cout << *f;
//     b->executeForm(*f);
//     delete b;
//     delete f;
//   } catch (std::exception& e) {
//     std::cerr << e.what() << "\n";
//   }

//   std::cout << "\n";

//   try {
//     b = new Bureaucrat("Pob", 20);
//     f = new PresidentialPardonForm("Pobbie");
//     std::cout << *b;
//     b->signForm(*f);
//     std::cout << *f;
//     b->executeForm(*f);
//     delete b;
//     delete f;
//   } catch (std::exception& e) {
//     std::cerr << e.what() << "\n";
//   }

//   std::cout << "\n";

//   return (0);
// }