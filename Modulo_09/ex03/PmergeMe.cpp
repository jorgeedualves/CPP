/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:09:22 by joeduard          #+#    #+#             */
/*   Updated: 2023/08/20 14:36:38 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
    return;
}
        
PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

PmergeMe::~PmergeMe(void)
{
    return;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    if (this != &rhs)
        *this = rhs;
    return (*this);
}

bool PmergeMe::loadList(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
	{
		int num = std::atoi(argv[i]);

		if (num < 0)
			return (false);        
		_arrayVector.push_back(num);
        _arrayList.push_back(num);
	}
	return (true);
}

bool PmergeMe::hasDuplicate(void)
{
    _orderedList = this->_input;
    std::sort(_orderedList.begin(), _orderedList.end(), &PmergeMe::compare);

    std::vector<int> intersection;
    std::set_intersection(
        _input.begin(), _input.end(),
        _orderedList.begin(), _orderedList.end(),
        std::back_inserter(intersection)
    );
    return !intersection.empty(); // If intersection is not empty, there are duplicates
}

bool PmergeMe::compare(unsigned int a, unsigned int b)
{
	return a < b;
}

void PmergeMe::printUnsorted(void)
{
    int i = 0;

    for (std::list<unsigned int>::const_iterator it = _input.begin();it != _input.end(); ++it)
    {
        std::cout <<*it << " ";
        i++;
        if (i >= 15)
        {
            std::cout << "[...]";
            break;
        }
    }
    std::cout <<std::endl;
}

void PmergeMe::printSorted(void)
{
    int i = 0;

    for (std::list<unsigned int>::const_iterator it = _orderedList.begin(); it != _orderedList.end(); ++it)
    {
        std::cout << *it << " ";
        i++;
        if (i >=15)
        {
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;
}

size_t PmergeMe::containerSize(void)
{
    return this->_input.size();
}



/* Ford-Johnson algoritm */
void PmergeMe::sortVector(void)
{
    uint *straggler = NULL;
    std::vector<std::pair<uint, uint>>pairs;
    std::vector<uint> mainSeq, pendingSeq, jacobSeq,indexSeq;

    if (_arrayVector.size() < 2 || isSorted(_arrayVector))
    {
        return;
    }
    if (hasStraggler(_arrayVector))
    {
        straggler = &_arrayVector.back();
        _arrayVector.pop_back();
    }
    pairs = createVectorPairs(_arrayVector);
    sortPairs(pairs);
    insertionSortByLargestValue(pairs, pairs.size());
    mainSeq = createVectorMainseq(pairs);
    pendingSeq = createVectorPendingSeq(pairs);
    jacobSeq = createJacobsthalSeq(pendingSeq);
}

std::vector<std::pair<uint, uint>>PmergeMe::createVectorPairs(std::vector<uint> &arrayVector)
{
    std::vector<uint>::iterator it, next;
    std::vector<std::pair<uint, uint>>pairs;

    it = arrayVector.begin();
    while (it != arrayVector.end())
    {
        next = it + 1;
        pairs.push_back(std::make_pair(*it, *next));
        it += 2;
    }
    return (pairs);
}

std::vector<uint>createVectorMainseq(std::vector<std::pair<uint, uint>> &pairs)
{
    std::vector<uint> mainSeq;
    std::vector<std::pair<uint, uint>>::iterator it = pairs.begin();

    for (it = pairs.begin(); it != pairs.end(); it++)
    {
        mainSeq.push_back(it->second);
    }
    return (mainSeq);
}


std::vector<uint>PmergeMe::createVectorPendingSeq(std::vector<std::pair<uint, uint> > &pairs)
{
    std::vector<uint> mainSeq;
    std::vector<std::pair<uint, uint>>::iterator it;

    for (it = pairs.begin(); it != pairs.end(); it++)
    {
        mainSeq.push_back(it->first);
    }
    return (mainSeq);
}



void PmergeMe::binaryListInsert(unsigned int value)
{

}

void PmergeMe::binaryVectorInsert(unsigned int value)
{

}
