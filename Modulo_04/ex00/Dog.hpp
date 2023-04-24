/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:53:31 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/24 17:56:30 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
    Dog(void);
    Dog(Dog const &src);
    virtual ~Dog();

    Dog &operator=(Dog const &rhs);

    void makeSound(void) const;

};

#endif
