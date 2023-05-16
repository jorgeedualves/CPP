/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:52:24 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/16 17:21:25 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base* generate(void)
{
    unsigned int seed = static_cast<unsigned int>(time(0));
    int ranNum = rand_r(&seed) % (3);


    switch (ranNum)
    {
        case 0:
            return (new A());
            break;
        case 1:
            return (new B());
            break;
        case 2:
            return (new C());
            break;
        default:
            return (NULL);
            break;
    }
}


void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type: A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "Type B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "Type C\n";
    else 
        std::cerr << "invalid pointer\n";
}

void identify(Base& p)
{
    try
    {
        A a = dynamic_cast<A&>(p);
        std::cout << "Type: A\n";
    }
    catch (const std::exception& e1)
    {
        try
        {
            B b = dynamic_cast<B&>(p);
            std::cout << "Type: B\n";
        }
        catch (const std::exception& e2)
        {
            try
            {
                C c = dynamic_cast<C&>(p);
                std::cout << "Type: C\n";
            }
            catch(const std::exception& e)
            {
                std::cerr << "Invalid reference\n";
            }
        }
    }
}