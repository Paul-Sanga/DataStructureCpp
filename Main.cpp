#include<iostream>
#include"List.h"
#include"Stack.h"

int main()
{
	//Linked List
	LinkedList<int> col;
	col.PushFront(6);
	col.PushBack(7);
	col.PushFront(5);
	col.PushBack(8);

	std::cout << col << std::endl;

	// Doubly-Linked List
	DLinkedList<int> list;

	list.PushFront(5);
	list.PushBack(6);
	list.PushFront(4);
	list.PushBack(7);

	auto head = list.Front();
	if (!head)
	{
		std::cout << "Head Error: " << head.error() << std::endl;
	}
	else
	{
		std::cout << "Head: " << *head << std::endl;
	}

	auto tail = list.Back();
	if (!tail)
	{
		std::cout << "Tail Error: " << tail.error() << std::endl;
	}
	else
	{
		std::cout << "Tail: " << *tail << std::endl;
	}

	std::cout << list << std::endl;
	std::cout << "DList Length Before Pop: " << list.Length() << std::endl;

	list.PopFront();
	//list.PopBack();
	//list.PopBack();
	//list.PopFront();

	auto head2 = list.Front();
	if (!head2)
	{
		std::cout << "Head Error: " << head2.error() << std::endl;
	}
	else
	{
		std::cout << "Head: " << *head2 << std::endl;
	}

	auto tail2 = list.Back();
	if (!tail2)
	{
		std::cout << "Tail Error: " << tail2.error() << std::endl;
	}
	else
	{
		std::cout << "Tail: " << *tail2 << std::endl;
	}
	std::cout << list << std::endl;
	std::cout << "DList Length After Pop: " << list.Length() << std::endl;

	// Stack section
	Stack<int> stack;
	stack.Push(5);
	stack.Push(6);
	stack.Push(7);
	stack.Pop();
	//std::cout << "Removed: " << stack.Pop() << " New Peek Is: " << stack.Peek() << std::endl;
	std::cout << "Stack Length: " << stack.Size() << std::endl;
	std::cout << "Stack Peek's: " << stack.Peek() << std::endl;

	return 0;
}