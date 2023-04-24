/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:37:31 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/24 17:53:14 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
    Cat(void);
    Cat(Cat const &src);
    virtual ~Cat(void);

    Cat &operator=(Cat const &rhs);

    void makeSound(void) const;
};
#endif