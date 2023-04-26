/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:37:31 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/26 18:08:34 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    public:
    Cat(void);
    Cat(Cat const &src);
    virtual ~Cat(void);

    Cat &operator=(Cat const &rhs);

    Brain const *getBrain(void) const;
    void makeSound(void) const;

    private:
        Brain* _brain;
};
#endif