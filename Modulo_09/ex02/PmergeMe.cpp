/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:04:57 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/24 17:26:35 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe(void)
{
    return;
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

template <typename T>
PmergeMe<T>::~PmergeMe(void)
{
    return;
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe<T> &rhs)
{
    if (this != &rhs)
        *this = rhs;
    return (*this);
}

template <typename T>
bool PmergeMe<T>::hasDuplicate(T &container)
{
    T sortedContainer = container;
    mergeSort(sortedContainer);
    return (std::unique(sortedContainer.begin(), sortedContainer.end()) != sortedContainer.end());
}

template <typename T>
void PmergeMe<T>::mergeSort(T &container)
{
    mergeSort(container, container.begin(), container.end());
}

template <typename T>
void PmergeMe<T>::mergeSort(T &container, typename T::iterator begin, typename T::iterator end)
{
    if (begin == end || ++begin == end)
        return;
    --begin;
    typename T::iterator middle = begin;
    std::advance(middle, std::distance(begin, end) / 2);
    
    mergeSort(container, begin, middle);
    mergeSort(container, middle, end);
    mergeMe(begin, middle, end);
}

template <typename T>
void PmergeMe<T>::mergeMe(typename T::iterator begin, typename T::iterator middle, typename T::iterator end)
{
    T left(begin, middle);
    T right(middle, end);
    
    typename T::iterator leftIt = left.begin();
    typename T::iterator rightIt = right.begin();
    typename T::iterator mergeIt = begin;

    while (leftIt != left.end() && rightIt != right.end())
    {
        if (*leftIt <= *rightIt)
        {
            *mergeIt = *leftIt;
            ++leftIt;
        }
        else
        {
            *mergeIt = *rightIt;
            ++rightIt;
        }
        ++mergeIt;
    }
    while (leftIt != left.end())
    {
        *mergeIt = *leftIt;
        ++leftIt;
        ++mergeIt;
    }
    while (rightIt != right.end())
    {
        *mergeIt = *rightIt;
        ++rightIt;
        ++mergeIt;
    }
}

template <typename T>
void PmergeMe<T>::printMe(T &container)
{
    int i = 0;
    
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << " ";
        i++;
        if (i >= 15)
        {
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;
}

template class PmergeMe < std::deque<int> >;
template class PmergeMe < std::list<int> >;