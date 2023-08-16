/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:09:30 by joeduard          #+#    #+#             */
/*   Updated: 2023/08/15 21:29:57 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <algorithm>

class Pmergeme
{
    public:
        Pmergeme(void);
        Pmergeme(const Pmergeme &src);
        ~Pmergeme(void);

        Pmergeme &operator=(const Pmergeme &rhs);

        bool hasDuplicate(void);

        void printUnSorted(void);
        void printSorted(void);
        size_t constainerSize(void);

        void sortList(void);
        void sortVector(void);
        void binaryInsert(unsigned int value);

    private:
        std::list<unsigned int> _orderedList;
        std::vector<unsigned int> _oderedVector;

};

#endif
