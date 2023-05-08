/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:30:26 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/08 11:52:07 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{

public:
    Fixed(void);
    Fixed(Fixed const &src);
    ~Fixed(void);

    Fixed &operator=(Fixed const &src);

    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int _rawBits;
    static int const _fractionalBits;
};

#endif