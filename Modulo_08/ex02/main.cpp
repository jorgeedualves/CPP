/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:32:02 by joeduard          #+#    #+#             */
/*   Updated: 2023/05/19 18:39:35 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <stack>

#include "MutantStack.hpp"

int main(void)
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}


// int main(void) {
//   MutantStack<int> mstack;
//   std::list<int> mlist;

//   mlist.push_back(5);
//   mlist.push_back(17);

//   mstack.push(5);
//   mstack.push(17);

//   std::cout << "[ Teste 1: top ]\n";
//   std::cout << "Stack Mutant:  " << mstack.top() << "\n";
//   std::cout << "List Original: " << mlist.back() << "\n";

//   mlist.pop_back();
//   mstack.pop();

//   std::cout << "\n[ Teste 2: size ]\n";
//   std::cout << "Stack Mutant:  " << mstack.size() << "\n";
//   std::cout << "List Original: " << mlist.size() << "\n";

//   mlist.push_back(3);
//   mlist.push_back(5);
//   mlist.push_back(9);
//   mlist.push_back(0);

//   mstack.push(3);
//   mstack.push(5);
//   mstack.push(9);
//   mstack.push(0);

//   std::list<int>::iterator it2 = mlist.begin();
//   MutantStack<int>::iterator it = mstack.begin();
//   MutantStack<int>::iterator ite = mstack.end();

//   ++it2;
//   --it2;
//   ++it;
//   --it;

//   std::cout << "\n[ Teste 3: iterator ]\n";
//   while (it != ite) {
//     std::cout << "Mut: " << *it << " | ";
//     std::cout << "Ori: " << *it2 << "\n";
//     ++it;
//     ++it2;
//   }

//   MutantStack<int> s(mstack);
//   std::list<int> l(mlist);

//   std::cout << "\n[ Teste 4: (copy) top ]\n";
//   std::cout << "Stack Mutant:  " << s.top() << "\n";
//   std::cout << "List Original: " << l.back() << "\n";

//   std::cout << "\n[ Teste 5 (copy) size ]\n";
//   std::cout << "Stack Mutant:  " << s.size() << "\n";
//   std::cout << "List Original: " << l.size() << "\n";
//   return (0);
// }