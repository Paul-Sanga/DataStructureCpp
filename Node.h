#pragma once

#include<memory>

template<typename T>
class Node
{
private:
	T mData;
	std::unique_ptr<Node<T>> mNextNode;


public:
	Node(const T& data) : mData(data), mNextNode(nullptr) {}

	Node(Node<T>&& node) noexcept
	{
		mData = std::move(node.mData);
		mNextNode = std::move(node.mNextNode);

		node.mData = T();
		node.mNextNode = nullptr;
	}

	Node& operator=(Node<T>&& node) noexcept
	{
		if (this != &node)
		{
			mData = std::move(node.mData);
			mNextNode = std::move(node.mNextNode);

			node.mData = T();
			node.mNextNode = nullptr;
		}
		return *this;
	}

	T& Data() { return mData; }

	void SetNextNode(std::unique_ptr<Node<T>> nodePtr)
	{
		mNextNode = std::move(nodePtr);
	}

	std::unique_ptr<Node<T>>& Next()
	{
		return mNextNode;
	}

	Node<T>* NextPtr() const
	{
		return mNextNode.get();
	}
};