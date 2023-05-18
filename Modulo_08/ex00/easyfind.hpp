/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:03:02 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/18 17:21:05 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <deque>
#include <exception>
#include <list>
#include <string>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &constainer, int value);

#include "easyfind.tpp"

#endif