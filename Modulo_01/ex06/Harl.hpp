/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:32:03 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/04 16:32:13 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl{

    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    
    public:
        Harl();
        ~Harl() { }
        void complain(std::string level);
};

#endif