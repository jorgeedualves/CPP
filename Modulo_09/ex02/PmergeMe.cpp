/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:40:47 by azamario          #+#    #+#             */
/*   Updated: 2023/08/30 20:21:39 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "PmergeMe.tpp"

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

bool PmergeMe::loadNumber(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        int number = std::atoi(argv[i]);

        if (number < 0)
        {
            return false;
        }

        this->_inputVector.push_back(number);
        this->_inputDeque.push_back(number);
    }
    return true;
}

bool PmergeMe::hasDuplicate(void)
{
    _checkDuplicate = this->_inputVector;
    std::sort(_checkDuplicate.begin(), _checkDuplicate.end(), &PmergeMe::compare);
    return (std::unique(_checkDuplicate.begin(), _checkDuplicate.end()) != _checkDuplicate.end());
}

bool PmergeMe::compare(unsigned int a, unsigned int b)
{
	return a < b;
}

void PmergeMe::printUnsorted(void)
{
    int i = 0;
    
    for (std::vector<unsigned int>::const_iterator it = _inputVector.begin(); it != _inputVector.end(); ++it)
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

void PmergeMe::printVectorSorted(void)
{
    int i = 0;
    
    for (std::vector<unsigned int>::const_iterator it = _orderedVector.begin(); it != _orderedVector.end(); ++it)
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

void PmergeMe::printDequeSorted(void)
{
    int i = 0;
    
    for (std::deque<unsigned int>::const_iterator it = _orderedDeque.begin(); it != _orderedDeque.end(); ++it)
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

size_t PmergeMe::containerSize(void)
{
	return this->_inputVector.size();
}


/*  -- Ford–Johnson VECTOR algorithm -- */

void PmergeMe::sortVector()
{
	int straggler = -1;
	_orderedVector = this->_inputVector;
	std::vector<std::pair<unsigned int, unsigned int> > pairs;
  	std::vector<unsigned int> mainSequence, pendingSeq, jacobSeq, indexSeq;

  	if (_orderedVector.size() < 2 or isSortedAscending(_orderedVector))
	{
		return;
  	}
  	if (hasStraggler(_orderedVector))
	{
    	straggler = _orderedVector.back();
    	_orderedVector.pop_back();
  	}
 	pairs = createVectorPairs(_orderedVector);
	sortPairs(pairs);
  	insertionSortByLargestValue(pairs, pairs.size());
 	mainSequence = createVectormainSequence(pairs);
	pendingSeq = createVectorPendingSeq(pairs);
	jacobSeq = createJacobsthalSequence(pendingSeq);
  	indexSeq = createIndexSequence(jacobSeq, pendingSeq);
    fillMainSequence(mainSequence, indexSeq, pendingSeq);
  	if (straggler >= 0)
    	insertStragglerElement(mainSequence, straggler);
	_orderedVector.assign(mainSequence.begin(), mainSequence.end());
}

std::vector<std::pair<uint, uint> >
PmergeMe::createVectorPairs(std::vector<uint> &_orderedVector)
{
	std::vector<uint>::iterator it, next;
  	std::vector<std::pair<uint, uint> > pairs;

  	it = _orderedVector.begin();
  	while (it != _orderedVector.end())
	{
    	next = it + 1;
    	pairs.push_back(std::make_pair(*it, *next));
    	it += 2;
  	}
  	return (pairs);
}

std::vector<uint> PmergeMe::createVectormainSequence(std::vector<std::pair<uint, uint> > &pairs)
{
  std::vector<uint> mainSequence;
  std::vector<std::pair<uint, uint> >::iterator it = pairs.begin();

  for (it = pairs.begin(); it != pairs.end(); it++)
  {
	mainSequence.push_back(it->second);
  }
  return (mainSequence);
}

std::vector<uint> PmergeMe::createVectorPendingSeq(std::vector<std::pair<uint, uint> > &pairs)
{
  std::vector<uint> mainSequence;
  std::vector<std::pair<uint, uint> >::iterator it;

  for (it = pairs.begin(); it != pairs.end(); it++)
  {
    mainSequence.push_back(it->first);
  }
  return (mainSequence);
}


/*  -- Ford–Johnson DEQUE algorithm -- */

void PmergeMe::sortDeque()
{
	int straggler = -1;
	_orderedDeque = this->_inputDeque;
	std::deque<std::pair<unsigned int, unsigned int> > pairs;
  	std::deque<unsigned int> mainSequence, pendingSeq, jacobSeq, indexSeq;

  	if (_orderedDeque.size() < 2 or isSortedAscending(_orderedDeque))
	{
		return;
  	}
  	if (hasStraggler(_orderedDeque))
	{
    	straggler = _orderedDeque.back();
    	_orderedDeque.pop_back();
  	}
 	pairs = createDequePairs(_orderedDeque);
	sortPairs(pairs);
  	insertionSortByLargestValue(pairs, pairs.size());
 	mainSequence = createDequemainSequence(pairs);
	pendingSeq = createDequePendingSeq(pairs);
	jacobSeq = createJacobsthalSequence(pendingSeq);
  	indexSeq = createIndexSequence(jacobSeq, pendingSeq);
    fillMainSequence(mainSequence, indexSeq, pendingSeq);
  	if (straggler >= 0)
    	insertStragglerElement(mainSequence, straggler);
	_orderedDeque.assign(mainSequence.begin(), mainSequence.end());
}

std::deque<std::pair<uint, uint> > PmergeMe::createDequePairs(std::deque<uint> &arr)
{
	std::deque<uint>::iterator it, next;
  	std::deque<std::pair<uint, uint> > pairs;

  	it = arr.begin();
  	while (it != arr.end())
	{
    	next = it + 1;
    	pairs.push_back(std::make_pair(*it, *next));
    	it += 2;
  	}
  	return (pairs);
}

std::deque<uint> PmergeMe::createDequemainSequence(std::deque<std::pair<uint, uint> > &pairs)
{
	std::deque<uint> mainSequence;
  	std::deque<std::pair<uint, uint> >::iterator it = pairs.begin();

  	for (it = pairs.begin(); it != pairs.end(); it++)
	{
    	mainSequence.push_back(it->second);
  	}
  	return (mainSequence);
}

std::deque<uint> PmergeMe::createDequePendingSeq(std::deque<std::pair<uint, uint> > &pairs)
{
	std::deque<uint> mainSequence;
   std::deque<std::pair<uint, uint> >::iterator it;

  	for (it = pairs.begin(); it != pairs.end(); it++)
	{
    	mainSequence.push_back(it->first);
  	}
  	return (mainSequence);
}


/*  -- Ford–Johnson Jacobsthal number -- */

int PmergeMe::jacobsthal(int n)
{
  if (n == 0)
    return (0);
  if (n == 1)
    return (1);
  return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}
