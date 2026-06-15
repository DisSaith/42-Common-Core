/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:00:47 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/09 11:50:12 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <stack>

int	main( void )
{
	MutantStack_bis<int>	mbisstack;
	MutantStack<int>		mstack;
	std::stack<int>			stack;
	std::deque<int>			deque;
	std::list<int>			list;
	
	stack.push(5);
	stack.push(17);
	mbisstack.push(5);
	mbisstack.push(17);
	mstack.push(5);
	mstack.push(17);
	deque.push_front(5);
	deque.push_front(17);
	list.push_back(5);
	list.push_back(17);
	
	std::cout << std::endl <<"stack.top() = " << stack.top() << std::endl;
	std::cout << "mbisstack.top() = " << mbisstack.top() << std::endl;
	std::cout << "mstack.top() = " << mstack.top() << std::endl;
	std::cout << "deque.top() = " << deque.front() << std::endl;
	std::cout << "list.top() = " << list.back() << std::endl;
	stack.pop();
	mbisstack.pop();
	mstack.pop();
	deque.pop_front();
	list.pop_back();
	std::cout << "stack.size() = " << stack.size() << std::endl;
	std::cout << "mbisstack.size() = " << mbisstack.size() << std::endl;
	std::cout << "mstack.size() = " << mstack.size() << std::endl;
	std::cout << "deque.size() = " << deque.size() << std::endl;
	std::cout << "list.size() = " << list.size() << std::endl << std::endl;
	
	stack.push(3);
	stack.push(5);
	stack.push(737);
	stack.push(0);

	mbisstack.push(3);
	mbisstack.push(5);
	mbisstack.push(737);
	mbisstack.push(0);

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	deque.push_front(3);
	deque.push_front(5);
	deque.push_front(737);
	deque.push_front(0);

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	
	std::deque<int>::iterator	it2 = deque.begin();
	std::deque<int>::iterator	ite2 = deque.end();
	std::list<int>::iterator	it3 = list.begin();
	std::list<int>::iterator	ite3 = list.end();
	//MutantStack_bis<int>::iterator	it1 = mbisstack.begin();
	//MutantStack_bis<int>::iterator	ite1 = mbisstack.end();
	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
	++it;
	//++it1;
	--it;
	//--it1;
	std::cout << "------ [Stack] ------\n";
	while (stack.empty() != true)
	{
		std::cout << stack.top() << std::endl;
		stack.pop();
	}
	std::cout << "\n------ [MutantStack_bis] ------\n";
	while (mbisstack.empty() != true)
	{
		std::cout << mbisstack.top() << std::endl;
		mbisstack.pop();
	}
	/*while (it1 != ite1)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}*/
	std::cout << "\n------ [MutantStack] ------\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "\n------ [Deque] ------\n";
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::cout << "\n------ [List] ------\n";
	while (it3 != ite3)
	{
		std::cout << *it3 << std::endl;
		++it3;
	}
	
	std::stack<int> s(mstack);
	
	return 0;
	
	//OLDER TESTS
	/*
	MutantStack<int>	tab;
	std::stack<int>		tab2;
	
	tab.push( 1 );
	tab.push( 42 );
	tab.push( 17 );
	tab.pop();
	
	tab2.push( 1 );
	tab2.push( 42 );
	tab2.push( 17 );
	tab2.pop();

	std::cout << "------- [TEST Iterators] -------\n";
	MutantStack<int>::iterator	it = tab.begin();
	MutantStack<int>::iterator	it2 = tab.end();
	std::cout << "tab.begin() = " << *it << std::endl;
	++it;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "tab.end() = " << *it2 << std::endl << std::endl;

	std::cout << "-------- [TEST methodes] --------\n";
	std::cout << "tab.top() = " << tab.top() << std::endl;
	std::cout << "tab2.top() = " << tab2.top() << std::endl << std::endl;

	std::cout << "tab.size() = " << tab.size() << std::endl;
	if ( tab.empty() == true )
		std::cout << "tab.empty() -> " << "tab is empty.\n\n";
	else
		std::cout << "tab.empty() -> " << "tab isn't empty.\n\n";

	std::cout << "tab2.size() = " << tab2.size() << std::endl;
	if ( tab2.empty() == true )
		std::cout << "tab2.empty() -> " << "tab2 is empty.\n";
	else
		std::cout << "tab2.empty() -> " << "tab2 isn't empty.\n";
	
	return (0);
	*/
}
