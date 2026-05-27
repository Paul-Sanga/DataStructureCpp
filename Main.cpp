#include<iostream>
#include"List.h"

int main()
{
	LinkedList<int> list;
	list.PushFront(5);
	list.PushBack(6);
	list.PushFront(4);
	list.PushBack(7);

	std::cout << list << std::endl;

	return 0;
}