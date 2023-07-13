/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:24:51 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 13:24:53 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>

#include "MutantStack.hpp"

int main( void )
{
	std::cout << std::endl;

	{
		std::cout << "MutantStack\n{" << std::endl;

		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "   top: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << std::endl;

		std::cout << "   size: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(99);
		mstack.push(18);
		mstack.push(20);
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		std::cout << std::endl << "   numbers: ";

		while (it != ite)
		{
			std::cout << *it;
			if (it < ite - 1)
				std::cout << ", ";
			++it;
		}

		std::stack<int> s(mstack);

		std::cout << "\n}\n" << std::endl;
	}

	
	{
		std::cout << "List\n{" << std::endl;

		std::list<int> lstack;

		lstack.push_back(5);
		lstack.push_back(17);

		std::cout << "   top: " << lstack.back() << std::endl;

		lstack.pop_back();

		std::cout << std::endl;

		std::cout << "   size: " << lstack.size() << std::endl;

		lstack.push_back(3);
		lstack.push_back(5);
		lstack.push_back(737);
		lstack.push_back(99);
		lstack.push_back(18);
		lstack.push_back(20);
		lstack.push_back(0);
		
		std::list<int>::iterator it = lstack.begin();
		std::list<int>::iterator ite = lstack.end();

		std::cout << std::endl << "   numbers: ";

		long unsigned int i = 1;

		while (it != ite)
		{
			std::cout << *it;
			if (i++ < lstack.size())
				std::cout << ", ";
			++it;
		}

		std::cout << "\n}\n" << std::endl;
	}

	return (0);

}
