#include "stack.hpp"
#include <stdlib.h>
#include <string>
#include <chrono>
#include <thread>

template <typename T> 
void producer(stack<T> &Stack)
{
	for(;;)
	{
		Stack.push(std::rand() % 100);
		std::this_thread::sleep_for(std::chrono::seconds(std::rand() % (3) + 1));
	}
}

void consumer(stack<T> &Stack)
{
	for(;;)
	{
		Stack.pop();
		std::this_thread::sleep_for(std::chrono::seconds(std::rand() % (3) + 2));
	}	
}

int main()
{
	stack<int> Stack;
	
	std::thread prod(producer, std::ref(Stack));
	std::thread cons(consumer, std::ref(Stack));
	
	prod.join();
	cons.join();

	system("pause");
	return 0;
}
