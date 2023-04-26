/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:04:37 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/26 18:24:40 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal{
    public:
    AAnimal(void);
    explicit AAnimal(std::string const type);
	AAnimal(AAnimal const &src);
    virtual ~AAnimal(void);

    AAnimal &operator=(AAnimal const &rhs);
    
	std::string const getType(void) const;
	void setType(std::string const type);
	virtual void makeSound(void) const = 0;

    protected:
    std::string _type;
};

std::ostream &operator <<(std::ostream &out, AAnimal const &in);

#endif