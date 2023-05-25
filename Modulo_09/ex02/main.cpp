/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:43:27 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/24 17:18:27 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>

int main(int argc, char *argv[])
{
    std::cout << std::endl;

    if (argc < 2)
	{
		std::cerr << "Error: Missing arguments\n" << std::endl;
		return (1);
	}

	std::deque<int> dequeSequence;
	std::list<int> listSequence;
	PmergeMe<std::deque<int> > mergeMeDeque;
	PmergeMe<std::list<int> > mergeMeList;
	
	for (int i = 1; i < argc; ++i)
	{
        int num = std::atoi(argv[i]);

        if (num <= 0)
        {
            std::cout << "Error: Only positive integers are allowed\n" << std::endl;
            return (1);
        }
        dequeSequence.push_back(num);
        listSequence.push_back(num);
    }

	if (mergeMeDeque.hasDuplicate(dequeSequence) || mergeMeList.hasDuplicate(listSequence))
    {
      std::cout << "Error: Duplicated numbers.\n" << std::endl;
      return (1);
    }

	clock_t start;
    clock_t end;

    std::cout << "Before: ";
	mergeMeDeque.printMe(dequeSequence);

    start = clock();
	mergeMeDeque.mergeSort(dequeSequence);
	end = clock();

    std::cout << "After: ";
	mergeMeDeque.printMe(dequeSequence);
    std::cout << std::endl;
	std::cout   << "Time to process a range of " << dequeSequence.size() 
                << " elements with std::deque : " << static_cast<double>(end - start) / CLOCKS_PER_SEC
                << " seconds" << std::endl;

	start = clock();
	mergeMeList.mergeSort(listSequence);
	end = clock();
    
	std::cout << "Time to process a range of " << listSequence.size()
				<< " elements with std::list : " << static_cast<double>(end - start) / CLOCKS_PER_SEC
				<< " seconds" << std::endl;

    std::cout << std::endl;

	return (0);
}

