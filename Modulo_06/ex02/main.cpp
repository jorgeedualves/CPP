/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:18:43 by joeduard          #+#    #+#             */
/*   Updated: 2023/07/13 13:18:45 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main( void )
{
	Base*	base;

	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		base = generate();

		if (!base)
			return (1);

		identify(base);
		identify(*base);

		delete base;
	}	
	std::cout << std::endl;

	return (0);
}
