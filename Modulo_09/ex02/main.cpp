/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:04:54 by azamario          #+#    #+#             */
/*   Updated: 2023/08/24 20:58:54 by joeduard         ###   ########.fr       */
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

	std::cout << "---- VECTOR ----" << std::endl;
    std::cout << "Before: ";
	input.printUnsorted();

    start = clock();
	input.sortVector();
	end = clock();

    std::cout << "After: ";
	input.printVectorSorted();
    std::cout << std::endl;
	std::cout   << "Time to process a range of " << input.containerSize() 
                << " elements with std::vector : " << static_cast<double>(end - start) / CLOCKS_PER_SEC
                << " seconds" << "\n" << std::endl;

	std::cout << "---- DEQUE ----" << std::endl;
    std::cout << "Before: ";
	input.printUnsorted();

    start = clock();
	input.sortDeque();
	end = clock();

    std::cout << "After: ";
	input.printDequeSorted();
    std::cout << std::endl;
	std::cout   << "Time to process a range of " << input.containerSize() 
                << " elements with std::deque : " << static_cast<double>(end - start) / CLOCKS_PER_SEC
                << " seconds" << std::endl;

    std::cout << std::endl;

	return (0);
}
