/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:59:05 by azamario          #+#    #+#             */
/*   Updated: 2023/06/26 12:30:45 by azamario         ###   ########.fr       */
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
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator iter = std::find(container.begin(), container.end(), value);
    
    if(iter == container.end())
    {
        throw std::runtime_error(std::string("Value not found\n"));
    }
    return (iter);
}

#endif
