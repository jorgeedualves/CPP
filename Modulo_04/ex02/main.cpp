/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:18:41 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/27 17:07:08 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main (void)
{
    Cat *cat = new Cat();
    const AAnimal *animals[6];
  //  const AAnimal animal; // Objeto da classe abstrata tipo "AAnimal" não é permitido

    std::cout << "**|Brain: |**\n";
    std::cout << *cat->getBrain();
    std:: cout << "\n";
    delete cat;
    std:: cout << "\n";

    std::cout << "**|Dog - Constructors: |**\n";
    for (int i = 0; i < 3; i++)
    {
        animals[i] = new Dog();
    }
    
    std::cout << "\n**|Cat - Constructors: **|\n";
    for (int i = 3; i < 6; i++)
    {
        animals[i] = new Cat();
    }

    std::cout << "\n**Dog - Destructors: **\n";
    for (int i = 0; i < 3; i++)
    {
        delete animals[i];
    }

    std::cout << "\n**Cat - Destructors: **\n";
    for (int i = 3; i < 6; i++)
    {
        delete animals[i];
    }


    return(0);
}