/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:36:34 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/25 17:39:46 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();
    const WrongCat *wrongCat2 = new WrongCat();

    std::cout << "\nType:\n";
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    std::cout << wrongMeta->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    std::cout << wrongCat2->getType() << " " << std::endl;
    
    std::cout << "\nMake Sound: \n";
    std::cout << *j << " - "; j->makeSound(); //will output the cat sound!
    std::cout << *i << " - "; i->makeSound();
    std::cout << *meta << " - "; meta->makeSound();
    std::cout << *wrongMeta << " - "; wrongMeta->makeSound();
    std::cout << *wrongCat << " - "; wrongCat->makeSound();
    std::cout << *wrongCat2 << " - "; wrongCat2->makeSound();
    std::cout << "\n";

    delete j;
    delete i;
    delete meta;
    delete wrongMeta;
    delete wrongCat;
    delete wrongCat2;

return 0;
}