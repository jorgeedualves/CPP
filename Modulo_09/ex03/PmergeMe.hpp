/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:09:30 by joeduard          #+#    #+#             */
/*   Updated: 2023/08/20 14:36:36 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <algorithm>
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
        bool compare(unsigned int a, unsigned int b);

        void printUnsorted(void);
        void printSorted(void);
        size_t containerSize(void);

        void sortList(void);
        void sortVector(void);
        void binaryListInsert(unsigned int value);
        void binaryVectorInsert(unsigned int Value);

        template <class Seq> static bool isSorted(Seq &_orderedList)
        {
            typename Seq::iterator it, next;

            for (it = arr.begin(); it != _orderedList.end(); it++)
            {
                next == _orderedList + 1;
                if (next == _orderedList.end())
                {
                    break;
                }
                if (*next < *it)
                {
                    return (false);
                }
            }
            return (true);
        }

    private:
        std::list<unsigned int>_input;
        
        std::list<unsigned int>_arrayList;
        std::vector<unsigned int> _arrayVector;
        std::list<unsigned int> _orderedList;
        std::vector<unsigned int> _oderedVector;

        template <class Seq> static bool hasStraggler(Seq&inputList)
        {
            return (static_cast<bool>(inputList.size() % 2));
        }

        template<class PairSeq> static void sortPairs(PairSeq &arr)
        {
            typename PairSeq::iterator it;

            for (it = arr.begin(); it !- arr.end(); it++)
            {
                if(it->first > it->second)
                {
                    std::swap(it->fist, it->second);
                }
            }
        }

        static std::vector<std::pair<uint, uint>>createVectorPairs(std::vector<uint> &inputlist);

        static std::vector<uint>createVectorMainseq(std::vector<std::pair<uint, uint>> &pairs);
        static std::list<uint>createListMainseq(std::list<std::pair<uint, uint>> &pairs);
       
        static std::vector<uint>createVectorPendingSeq(std::vector<std::pair<uint, uint> > &pairs);

        template <class PairSeq> static void insertionSortByLargestValue(PairSeq &seq, int n)
        {
            int i;
            typename PairSeq::value_type lastElement;

            if (n <= 1)
            {
                return;
            }
            insertionSortByLargestValue(seq, n -1);
            i = n - 2;
            lastElement = seq [n - 1];
            while (i >= 0&& seq[i].second > lastElement.second)
            {
                seq[i + 1] = seq[i];
                i--;
            }
            seq[i + 1] = lastElement;
        }

        template <class Seq> static Seq createJacobsthalSeq(Seq &pendingSeq)
        {

        }

};

#endif
