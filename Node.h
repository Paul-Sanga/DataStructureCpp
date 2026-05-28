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

	Node(Node<T>& node) = delete;

	Node& operator=(Node<T>& node) = delete;

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

template<typename T>
class DNode
{
	private:
		T mData;
		std::unique_ptr<DNode<T>> mNextNode;
		DNode<T>* mPrevNode;

	public:
		DNode(T data) : mData(data), mNextNode(nullptr), mPrevNode(nullptr) {}

		DNode(DNode<T>&& node)
		{
			mData = node.mData;
			mNextNode = std::move(node.mNextNode);
			mPrevNode = node.mPrevNode;

			node.mData = T();
			node.mPrevNode = nullptr;
		}

		DNode& operator=(DNode<T>&& node)
		{
			if (this != &node)
			{
				mData = node.mData;
				mNextNode = std::move(node.mNextNode);
				mPrevNode = node.mPrevNode;

				node.mData = T();
				node.mPrevNode = nullptr;
			}
			return *this;
		}

		DNode(DNode<T>& node) = delete;
		DNode& operator=(DNode<T>& node) = delete;

		T& Data() { return mData; }

		DNode<T>* Prev() const { return mPrevNode; }

		DNode<T>* Next() const { return mNextNode.get(); }

		void SetNextNode(std::unique_ptr<DNode<T>> nodePtr)
		{
			mNextNode = std::move(nodePtr);
		}

		void SetPrevNode(DNode<T>* prevNodePtr)
		{
			mPrevNode = prevNodePtr;
		}

		std::unique_ptr<DNode<T>>& NextPtr()
		{
			return mNextNode;
		}
};