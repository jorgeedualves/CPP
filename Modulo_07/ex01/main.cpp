/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:47:47 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/17 10:54:45 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6 ,7 ,8 ,9};
    char arr2[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    float arr3[10] = {0.0f, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f};

    std::cout << "*** INT ***\n";
    iter(arr, 10, printArr);
    std::cout << "\n\n";

    std::cout << "*** CHAR ***\n";
    iter(arr2, 10, printArr);
    std::cout << "\n\n";

    std::cout << "*** FLOAT ***\n";
    iter(arr3, 10, printArr);
    std::cout << "\n";

    return (0);
}