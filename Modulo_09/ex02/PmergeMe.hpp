/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:56:20 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/24 17:27:17 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>

template <typename T>
class PmergeMe
{
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe<T> &src);
        ~PmergeMe(void);

        PmergeMe &operator=(const PmergeMe<T> &rhs);

        bool hasDuplicate(T &container);
        void mergeSort(T &container);
        void mergeSort(T &container, typename T::iterator begin, typename T::iterator end);
        void mergeMe(typename T::iterator begin, typename T::iterator middle, typename T::iterator end);
        void printMe(T &container);
};

#endif