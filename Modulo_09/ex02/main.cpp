/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:26:18 by joeduard          #+#    #+#             */
/*   Updated: 2023/08/19 00:51:37 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    std::cout << std::endl;

	PmergeMe input;
	clock_t start;
    clock_t end;

    if (argc < 2)
	{
		std::cerr << "Error: Missing arguments\n" << std::endl;
		return (1);
	}

	if (!input.loadList(argc, argv))
	{
		std::cerr << "Error: Negative number not allowed\n" << std::endl;
		return (1);
	}

	if (input.hasDuplicate())
    {
      std::cerr << "Error: Duplicated numbers not allowed\n" << std::endl;
      return (1);
    }

    std::cout << "Before: ";
	input.printUnsorted();

    start = clock();
	input.sortVector();
	end = clock();

    std::cout << "After: ";
	input.printSorted();
    std::cout << std::endl;
	std::cout   << "Time to process a range of " << input.containerSize() 
                << " elements with std::vector : " << static_cast<double>(end - start) / CLOCKS_PER_SEC
                << " seconds" << std::endl;

    start = clock();
	input.sortList();
	end = clock();

    std::cout << std::endl;
	std::cout   << "Time to process a range of " << input.containerSize() 
                << " elements with std::list : " << static_cast<double>(end - start) / CLOCKS_PER_SEC
                << " seconds" << std::endl;

    std::cout << std::endl;

	return (0);
}
