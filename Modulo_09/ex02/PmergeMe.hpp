/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:26:40 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 13:26:42 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <algorithm>
#include <deque>
#include <vector>
#include <list>

class PmergeMe
{
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe &src);
        ~PmergeMe(void);

        PmergeMe &operator=(const PmergeMe &rhs);

		bool loadList(int argc, char **argv);
        bool hasDuplicate(void);
		static bool compare(unsigned int a, unsigned int b);

        void printUnsorted(void);
        void printSorted(void);
		size_t containerSize(void);

		void sortList(void);
		void binaryListInsert(unsigned int value);
		void sortVector(void);
		void binaryVectorInsert(unsigned int value);
		static bool pairCompare(std::pair<unsigned int, unsigned int> a, std::pair<unsigned int, unsigned int> b);

	private:
		std::deque<unsigned int> _inputDeque;
		std::deque<unsigned int> _orderedDeque;
		std::list<unsigned int> _orderedList;
		std::vector<unsigned int> _orderedVector;
};

#endif
