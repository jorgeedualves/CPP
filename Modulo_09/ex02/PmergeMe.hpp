/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:34:20 by azamario          #+#    #+#             */
/*   Updated: 2023/08/30 21:29:03 by joeduard         ###   ########.fr       */
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

		bool loadNumber(int argc, char **argv);
        bool hasDuplicate(void);
		static bool compare(unsigned int a, unsigned int b);

        void printUnsorted(void);
        void printVectorSorted(void);
        void printDequeSorted(void);
		size_t containerSize(void);

		void sortVector(void);
		void sortDeque(void);

		static int jacobsthal(int n);


	private:
		std::vector<unsigned int> _checkDuplicate;

		std::vector<unsigned int> _inputVector;
		std::vector<unsigned int> _orderedVector;

		std::deque<unsigned int> _inputDeque;
		std::deque<unsigned int> _orderedDeque;

		static std::vector<std::pair<uint, uint> >
  		createVectorPairs(std::vector<uint> &_orderedVector);

		static std::vector<uint>
  		createVectormainSequence(std::vector<std::pair<uint, uint> > &pairs);

		static std::vector<uint>
  		createVectorPendingSeq(std::vector<std::pair<uint, uint> > &pairs);

		static std::deque<std::pair<uint, uint> >
  		createDequePairs(std::deque<uint> &_orderedDeque);

		static std::deque<uint>
  		createDequemainSequence(std::deque<std::pair<uint, uint> > &pairs);

		static std::deque<uint>
  		createDequePendingSeq(std::deque<std::pair<uint, uint> > &pairs);

};

#endif
