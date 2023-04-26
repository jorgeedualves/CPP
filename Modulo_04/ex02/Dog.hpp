/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:53:31 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/26 18:09:24 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    public:
        Dog(void);
        Dog(Dog const &src);
        virtual ~Dog();

        Dog &operator=(Dog const &rhs);

        Brain const *getBrain(void) const;
        void makeSound(void) const;
    
    private:
        Brain* _brain;

};

#endif
