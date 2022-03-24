#include "main.hpp"

void	stack_test_print()
{
	std::cout << std::endl << "\e[1;34m";
	std::cout << "___________________________________________________________________________________________" << std::endl;
	std::cout << "  /$$$$$$  /$$$$$$$$ /$$$$$$   /$$$$$$  /$$   /$$       /$$$$$$$$ /$$$$$$$$  /$$$$$$  /$$$$$$$$" << std::endl;
	std::cout << " /$$__  $$|__  $$__//$$__  $$ /$$__  $$| $$  /$$/      |__  $$__/| $$_____/ /$$__  $$|__  $$__/" << std::endl;
	std::cout << "| $$  \\__/   | $$  | $$  \\ $$| $$  \\__/| $$ /$$/          | $$   | $$      | $$  \\__/   | $$" << std::endl;
	std::cout << "|  $$$$$$    | $$  | $$$$$$$$| $$      | $$$$$/           | $$   | $$$$$   |  $$$$$$    | $$" << std::endl;
	std::cout << " \\____  $$   | $$  | $$__  $$| $$      | $$  $$           | $$   | $$__/    \\____  $$   | $$" << std::endl;
	std::cout << " /$$  \\ $$   | $$  | $$  | $$| $$    $$| $$\\  $$          | $$   | $$       /$$  \\ $$   | $$" << std::endl;
	std::cout << "|  $$$$$$/   | $$  | $$  | $$|  $$$$$$/| $$ \\  $$         | $$   | $$$$$$$$|  $$$$$$/   | $$" << std::endl;
	std::cout << " \\______/    |__/  |__/  |__/ \\______/ |__/  \\__/         |__/   |________/ \\______/    |__/" << std::endl;
	std::cout << "|__________________________________________________________________________________________";
	std::cout << "\e[1;37m" << std::endl << std::endl;
}

void   stack_test()
{
	stack_test_print();
	ft::vector<int> vec;
	ft::stack<int> mystack;
	ft::stack<int> mystack2;
	std::cout << "\e[1;31mpush Test:\e[1;37m" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "Pushing --> |\e[1;32m" << i << "\e[1;37m|" << " to mystack..." << std::endl;
		mystack.push(i);
	}
	std::cout << "\e[1;31mRelational operators Test:\e[1;37m" << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "Pushing --> |\e[1;32m" << i << "\e[1;37m|" << " to mystack2..." << std::endl;
		mystack2.push(i);
	}
	if (mystack == mystack2)
		std::cout << "mystack and mystack2 are equal\n";
	if (mystack != mystack2)
		std::cout << "mystack and mystack2 are not equal\n";
	if (mystack < mystack2)
		std::cout << "mystack is less than mystack2\n";
	if (mystack > mystack2)
		std::cout << "mystack is greater than mystack2\n";
	if (mystack <= mystack2)
		std::cout << "mystack is less than or equal to mystack2\n";
	if (mystack >= mystack2)
		std::cout << "mystack is greater than or equal to mystack2\n";

	std::cout << "\e[1;31mSize Test:\e[1;37m" << std::endl;
	std::cout << "size: |\e[1;32m" << mystack.size() << "\e[1;37m|" << '\n';

	std::cout << "\e[1;31mPop Test:\e[1;37m" << std::endl;
	while (!mystack.empty())
	{
		std::cout << "Popping --> |\e[1;32m" << mystack.top() << "\e[1;37m|" << std::endl;
		mystack.pop();
	}
	std::cout << "\e[1;31mSize after Pop :\e[1;37m" << std::endl;
	std::cout << "size: |\e[1;32m" << mystack.size() << "\e[1;37m|" << std::endl;
}

















