/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:12:16 by joeduard          #+#    #+#             */
/*   Updated: 2023/01/31 21:48:37 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::endl;
using std::cout;
using std::toupper;

int main	(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	if (argc == 1)
	{
		cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return(0);
	}
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			cout << (char)(toupper(argv[i][j]));
			j++;
		}
		if (i != argc -1)
			cout << " ";
		i++;
	}
	cout << endl;
	return(0);
}