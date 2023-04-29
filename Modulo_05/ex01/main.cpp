/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:15:56 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/28 22:27:31 by joeduard         ###   ########.fr       */
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

    // try
    // {
    //     bureaucrat = new Bureaucrat("Joao 3", 2);
    //     form = new Form("Form 3", 1, 1);
    //     bureaucrat->decrementGrade();
    //     std::cout << "Bureaucrat: " << *bureaucrat << " -- Grade: " << bureaucrat->getGrade();
    //     std::cout << "\nFormulario: " << *form << " -- Signed: " << form->getSigned() << " -- Grade to sign: "
    //     << form->getGradeSign() << " -- Grade to Execute: " << form->getGradeExecute() << "\n"; 
    //     delete bureaucrat;
    //     delete form;    
    // }
    // catch (std::exception & exc)
    // {
    //     std::cerr << exc.what() << std::endl;
    // }

    // try
    // {
    //     bureaucrat = new Bureaucrat("Joao 4", 3);
    //     std::cout << "Bureaucrat: " << *bureaucrat << " -- Grade: " << bureaucrat->getGrade() << "\n";
    //     delete bureaucrat;
    //     form = new Form("Form high", -1, 1);
    //     delete form;  
    // }
    // catch(const std::exception& exc)
    // {
    //     std::cerr << exc.what() << std::endl;
    // }

    // try
    // {
    //     bureaucrat = new Bureaucrat("Raquel", 1);
    //     std::cout << "Bureaucrat: " << *bureaucrat << " -- Grade: " << bureaucrat->getGrade() << "\n";
    //     delete bureaucrat;
    //     form = new Form("Form high", -1, 1);
    //     delete form;  
    // }
    // catch(const std::exception& exc)
    // {
	// 	std::cout << "**catch Raquel**\n";
    //     std::cerr << exc.what() << std::endl;
    // }

	// try
    // {
    //     bureaucrat = new Bureaucrat("Rafaela", 1);
    //     std::cout << "Bureaucrat: " << *bureaucrat << " -- Grade: " << bureaucrat->getGrade() << "\n";
    //     delete bureaucrat;
    //     form = new Form("Form high", 151, 1);
    //     delete form;  
    // }
    // catch(const std::exception& exc)
    // {
	// 	std::cout << "**catch Rafaela**\n";
    //     std::cerr << exc.what() << std::endl;
    // }
    

    return (0);
}    



//     try
//     {
//         bureaucrat = new Bureaucrat("Rafaela", 1);
//         bureaucrat->incrementGrade();
//         std::cout << "Bureaucrat : "<< *bureaucrat << "\nGrade: " << bureaucrat->getGrade() << "\n";
//         delete bureaucrat;    
//     }
//     catch (std::exception & exc)
//     {
//         std::cerr << exc.what() << std::endl;
//     }

//     try
//     {
//         bureaucrat = new Bureaucrat("Rosana", 150);
//         bureaucrat->decrementGrade();
//         std::cout << "Bureaucrat : "<< *bureaucrat << "\nGrade: " << bureaucrat->getGrade() << "\n";
//         delete bureaucrat;    
//     }
//     catch (std::exception & exc)
//     {
//         std::cerr << exc.what() << std::endl;
//     }

//      try
//     {
//         bureaucrat = new Bureaucrat("Rita", 151);
//         std::cout << "Bureaucrat : "<< *bureaucrat << "\nGrade: " << bureaucrat->getGrade() << "\n";
//         delete bureaucrat;    
//     }
//     catch (std::exception & exc)
//     {
//         std::cerr << exc.what() << std::endl;
//     }
    
//     return (0);
// }
