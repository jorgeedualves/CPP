/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:31:04 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/26 11:07:24 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <sstream>

class Brain
{
    public:
        Brain(void);
        Brain(Brain const &src);
        ~Brain(void);

        Brain &operator=(Brain const &rhs);

        std::string getIdea(int const &in) const;
        void setIdea(int const &in, std::string const &idea);

    private:
        std::string _ideas[100];
};

std::ostream &operator<<(std::ostream &out, Brain const &in);

#endif