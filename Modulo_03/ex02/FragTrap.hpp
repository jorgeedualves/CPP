/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:16:06 by joeduard          #+#    #+#             */
/*   Updated: 2023/06/05 21:47:41 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    public:
        FragTrap(void);
        explicit FragTrap(std::string const name);
        FragTrap(FragTrap const &src);
        ~FragTrap(void);

        FragTrap &operator=(FragTrap const &rhs);

        void highFivesGuys(void);
};
#endif