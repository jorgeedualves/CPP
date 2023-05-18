/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:12:18 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/18 17:17:36 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template<typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator iter = std::find(container.begin(), container.end(), value);

    if (iter == container.end())
    {
        throw std::runtime_error(std::string("Value not found"));
    }
    return (iter);
}