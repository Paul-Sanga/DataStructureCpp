#pragma once

#include<expected>
#include<iostream>
#include"Node.h"

enum ListError
{
	ReadEmptyNodeError, DeleteFromEmptyListError
};

template<typename T>
class Iterator
{
private:
	Node<T>* mPtr;

public:
	Iterator(Node<T>* ptr) : mPtr(ptr) {}

	Iterator& operator++()
	{
		mPtr = mPtr->NextPtr();
		return *this;
	}

	Iterator& operator++(int)
	{
		Iterator temp = *this;
		++(*this);
		return temp;
	}

	T& operator*() const
	{
		return mPtr->Data();
	}

	T* operator->() const
	{
		return &(mPtr->Data());
	}

	friend bool operator==(const Iterator& lhs, const Iterator& rhs) { return lhs.mPtr == rhs.mPtr; }
	friend bool operator!=(const Iterator& lhs, const Iterator& rhs) { return lhs.mPtr != rhs.mPtr; }

};


template<typename T>
class LinkedList
{
public:
	using Iterator = ::Iterator<T>;

private:
	std::unique_ptr<Node<T>> mHead;
	Node<T>* mTail;
	size_t mLength;

public:
	LinkedList() : mHead(nullptr), mTail(nullptr), mLength(0) {}

	LinkedList(LinkedList<T>&& list)
	{
		mHead = std::move(list.mHead);
		mTail = list.mTail;
		mLength = list.mLength;

		list.mLength = 0;
		list.mTail = nullptr;
	}

	LinkedList<T>& operator=(LinkedList<T>&& list)
	{
		if (this != &list)
		{
			mHead = std::move(list.mHead);
			mTail = list.mTail;
			mLength = list.mLength;

			list.mTail = nullptr;
			list.mLength = 0;
		}
		return *this;
	}

	size_t Length() const { return mLength; }

	bool IsEmpty() const { return mLength == 0; }

	std::expected<T, ListError> Front() const
	{
		if (!mHead)
		{
			return std::unexpected(ListError::ReadEmptyNodeError);
		}
		else
		{
			return mHead->Data();
		}
	}

	std::expected<T, ListError> Back() const
	{
		if (!mTail)
		{
			return std::unexpected(ListError::ReadEmptyNodeError);
		}
		else
		{
			return mTail->Data();
		}
	}

	void PushFront(const T& data)
	{
		std::unique_ptr<Node<T>> node = std::make_unique<Node<T>>(data);

		if (IsEmpty())
		{
			node->SetNextNode(std::move(mHead));
			mHead = std::move(node);
			mTail = mHead.get();
		}
		else
		{
			node->SetNextNode(std::move(mHead));
			mHead = std::move(node);
		}
		mLength += 1;
	}

	void PushBack(const T& data)
	{
		std::unique_ptr<Node<T>> node = std::make_unique<Node<T>>(data);

		if (IsEmpty())
		{
			mHead = std::move(node);
			mTail = mHead.get();
		}
		else
		{
			Node<T>* rawNode = node.get();
			mTail->SetNextNode(std::move(node));
			mTail = rawNode;
		}
		mLength += 1;
	}

	void PopFront()
	{
		if (IsEmpty())
		{
			return;
		}
		else
		{
			std::unique_ptr<Node<T>> oldHead = std::move(mHead);
			mHead = std::move(oldHead->Next());

			if (!mHead)
			{
				mTail = nullptr;
			}
		}
		mLength -= 1;
	}

	Iterator begin() const { return Iterator(mHead.get()); }
	Iterator end() const { return Iterator(nullptr); }

	friend std::ostream& operator<<(std::ostream& stream, const LinkedList<T>& list)
	{
		stream << "[";

		auto it = list.begin();

		while (it != list.end())
		{
			stream << *it;
			++it;

			if (it != list.end())
			{
				stream << " -> ";
			}
		}

		stream << "]";
		return stream;
	}
};

