/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:11:50 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/24 17:37:17 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal{
    public:
    Animal(void);
    explicit Animal(std::string const type);
	Animal(Animal const &src);
    virtual ~Animal(void);

    Animal &operator=(Animal const &rhs);
    
	std::string const getType(void) const;
	void setType(std::string const type);
	virtual void makeSound(void) const;

    protected:
    std::string _type;
};

std::ostream &operator <<(std::ostream &out, Animal const &in);

#endif