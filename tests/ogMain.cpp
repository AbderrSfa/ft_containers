#include <vector>
#include <stack>
#include <iostream>

int		main() {
// ASSIGN
	std::cout << "\e[1;31mAssign Test:\e[1;37m" << std::endl;
	{
		std::vector<int> first;
		std::vector<int> second;
		std::vector<int> third;
		first.assign(7, 100); // 7 ints with a value of 100   
		std::vector<int>::iterator it;
		it = first.begin() + 1;
		second.assign(it, first.end() - 1); // the 5 central values of first  
		int myints[] = { 1776, 7, 4 };
	   // third.assign(myints, myints + 3); // assigning from array.    
		std::cout << "Size of first: " << int(first.size()) << '\n';
		std::cout << "Size of second: " << int(second.size()) << '\n';
		std::cout << "Size of third: " << int(third.size()) << '\n' << std::endl;
	}

	//   // SWAP(VECTOR)
	// std::cout << "\e[1;31mVector Swap Test:\e[1;37m" << std::endl;
	// {
	// 	std::vector<int> foo(3, 100); // three ints with a value of 100
	// 	std::vector<int> bar(5, 200); // five ints with a value of 200 
	// 	foo.swap(bar);
	// 	std::cout << "foo contains:";
	// 	for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
	// 		std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// 	std::cout << "bar contains:";
	// 	for (std::vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
	// 		std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// }
	// std::cout << "\e[1;31mVector Relational Operators Test:\e[1;37m" << std::endl;
	// {
	// 	std::vector<int> foo(3, 100); // three ints with a value of 100
	// 	std::vector<int> bar(2, 200); // two ints with a value of 200  

	// 	if (foo == bar)
	// 		std::cout << "foo and bar are equal\n";
	// 	if (foo != bar)
	// 		std::cout << "foo and bar are not equal\n";
	// 	if (foo < bar)
	// 		std::cout << "foo is less than bar\n";
	// 	if (foo > bar)
	// 		std::cout << "foo is greater than bar\n";
	// 	if (foo <= bar)
	// 		std::cout << "foo is less than or equal to bar\n";
	// 	if (foo >= bar)
	// 		std::cout << "foo is greater than or equal to bar\n";
	// 	std::cout << std::endl;
	// }

	//   // STACK TEST
	// std::vector<int> vec;
	// std::stack<int> mystack;
	// std::stack<int> mystack2;
	// std::cout << "\e[1;31mpush Test:\e[1;37m" << std::endl;
	// for (int i = 0; i < 5; ++i)
	// {
	// 	std::cout << "Pushing --> |\e[1;32m" << i << "\e[1;37m|" << " to mystack..." << std::endl;
	// 	mystack.push(i);
	// }
	// std::cout << "\e[1;31mRelational operators Test:\e[1;37m" << std::endl;
	// for (int i = 0; i < 3; ++i)
	// {
	// 	std::cout << "Pushing --> |\e[1;32m" << i << "\e[1;37m|" << " to mystack2..." << std::endl;
	// 	mystack2.push(i);
	// }
	// if (mystack == mystack2)
	// 	std::cout << "mystack and mystack2 are equal\n";
	// if (mystack != mystack2)
	// 	std::cout << "mystack and mystack2 are not equal\n";
	// if (mystack < mystack2)
	// 	std::cout << "mystack is less than mystack2\n";
	// if (mystack > mystack2)
	// 	std::cout << "mystack is greater than mystack2\n";
	// if (mystack <= mystack2)
	// 	std::cout << "mystack is less than or equal to mystack2\n";
	// if (mystack >= mystack2)
	// 	std::cout << "mystack is greater than or equal to mystack2\n";

	// std::cout << "\e[1;31mSize Test:\e[1;37m" << std::endl;
	// std::cout << "size: |\e[1;32m" << mystack.size() << "\e[1;37m|" << '\n';

	// std::cout << "\e[1;31mPop Test:\e[1;37m" << std::endl;
	// while (!mystack.empty())
	// {
	// 	std::cout << "Popping --> |\e[1;32m" << mystack.top() << "\e[1;37m|" << std::endl;
	// 	mystack.pop();
	// }
	// std::cout << "\e[1;31mSize after Pop :\e[1;37m" << std::endl;
	// std::cout << "size: |\e[1;32m" << mystack.size() << "\e[1;37m|" << std::endl;
}