/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:26:29 by joeduard          #+#    #+#             */
/*   Updated: 2023/08/15 21:10:21 by joeduard         ###   ########.fr       */
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
		this->_inputDeque.push_back(num);
	}
	return (true);
}

bool PmergeMe::hasDuplicate(void)
{
    _orderedDeque = this->_inputDeque;
    std::sort(_orderedDeque.begin(), _orderedDeque.end(), &PmergeMe::compare);
    return (std::unique(_orderedDeque.begin(), _orderedDeque.end()) != _orderedDeque.end());
}

bool PmergeMe::compare(unsigned int a, unsigned int b)
{
	return a < b;
}

void PmergeMe::printUnsorted(void)
{
    int i = 0;
    
    for (std::deque<unsigned int>::const_iterator it = _inputDeque.begin(); it != _inputDeque.end(); ++it)
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

void PmergeMe::printSorted(void)
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
	return this->_inputDeque.size();
}


/*  Ford–Johnson algorithm  */

void PmergeMe::sortVector()
{
	std::deque<unsigned int> copy(this->_inputDeque);
	std::deque<std::pair<unsigned int, unsigned int> > K_pairs;
	unsigned int bucket[2];
	this->_orderedVector.reserve(this->_inputDeque.size() + 2);
	while (copy.size() > 1)										
	{
		bucket[0] = copy.front();
		copy.pop_front();
		bucket[1] = copy.front();
		copy.pop_front();
		if (bucket[0] < bucket[1])
			K_pairs.push_back(std::make_pair(bucket[0],bucket[1]));
		else
			K_pairs.push_back(std::make_pair(bucket[1],bucket[0]));
	}
	//insert sort!
	std::sort(K_pairs.begin(), K_pairs.end(), &PmergeMe::pairCompare);
	for (std::deque<std::pair<unsigned int, unsigned int> >::iterator it = K_pairs.begin(); it < K_pairs.end(); it++)
	{
		this->_orderedVector.push_back((*it).second);
	}
	for (std::deque<std::pair<unsigned int, unsigned int> >::iterator it = K_pairs.begin(); it < K_pairs.end(); it++)
	{
		this->binaryVectorInsert((*it).first);
	}
	if (copy.size() == 1)
		this->binaryVectorInsert(copy.front());
};

void PmergeMe::sortList()
{
	std::deque<unsigned int> copy(this->_inputDeque);
	std::deque<std::pair<unsigned int, unsigned int> > K_pairs;
	unsigned int bucket[2];

	while (copy.size() > 1)
	{
		bucket[0] = copy.front();
		copy.pop_front();
		bucket[1] = copy.front();
		copy.pop_front();
		if (bucket[0] < bucket[1])
			K_pairs.push_back(std::make_pair(bucket[0],bucket[1]));
		else
			K_pairs.push_back(std::make_pair(bucket[1],bucket[0]));
	}
	std::sort(K_pairs.begin(), K_pairs.end(), &PmergeMe::pairCompare);
	for (std::deque<std::pair<unsigned int, unsigned int> >::iterator it = K_pairs.begin(); it < K_pairs.end(); it++)
	{
		this->_orderedList.push_back((*it).second);
	}
	for (std::deque<std::pair<unsigned int, unsigned int> >::iterator it = K_pairs.begin(); it < K_pairs.end(); it++)
	{
		this->binaryListInsert((*it).first);
	}
	if (copy.size() == 1)
		this->binaryListInsert(copy.front());
}
	
void PmergeMe::binaryVectorInsert(unsigned int value)
{
	std::vector<unsigned int>::iterator it = std::lower_bound(this->_orderedVector.begin(), this->_orderedVector.end(), value);
	this->_orderedVector.insert(it, value);
}

void PmergeMe::binaryListInsert(unsigned int value)
{
	std::list<unsigned int>::iterator it = std::lower_bound(this->_orderedList.begin(), this->_orderedList.end(), value);
	this->_orderedList.insert(it, value);
}

bool PmergeMe::pairCompare(std::pair<unsigned int, unsigned int> a, std::pair<unsigned int, unsigned int> b)
{
	return (a.second < b.second);
}
