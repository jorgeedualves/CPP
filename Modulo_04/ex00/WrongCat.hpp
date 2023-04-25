/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:23:35 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/25 11:53:08 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        explicit WrongCat(std::string const type);
        WrongCat(WrongCat const &src);
        virtual ~WrongCat();

        WrongCat &operator=(WrongCat const &rhs);

        void makeSound(void) const;

};

#endif