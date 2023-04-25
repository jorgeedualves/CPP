/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:50:54 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/24 21:01:42 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
    public:
        WrongAnimal(void);
        explicit WrongAnimal(std::string const type);
        WrongAnimal(WrongAnimal const &src);
        virtual ~WrongAnimal(void);

        WrongAnimal &operator=(WrongAnimal const &rhs);

        std::string const getType(void) const;
        void setType(std::string const type);
        void makeSound(void) const;

    protected:
    std::string _type;
};

std::ostream &operator<<(std::ostream &out, WrongAnimal const &in);


#endif