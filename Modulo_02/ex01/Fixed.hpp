/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:01:54 by joeduard          #+#    #+#             */
/*   Updated: 2023/04/13 15:33:08 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{

public:
    Fixed(void);
    Fixed(Fixed const &src);
    explicit Fixed(int const n);
    explicit Fixed(float const f);
    ~Fixed(void);

    Fixed &operator=(Fixed const &src);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

private:
    int _rawBits;
    static int const _fractionalBits;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif