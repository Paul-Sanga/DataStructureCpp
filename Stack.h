#pragma once

#include"Node.h"

enum StackError
{
	AttemptToReadFromEmptyStack
};

template<typename T>
class Stack
{
	private:
		std::unique_ptr<Node<T>> mPeek;
		Node<T>* mBase;
		size_t mLength;

	public:
		Stack() : mPeek(nullptr), mBase(nullptr), mLength(0) {}

		Stack(Stack<T>&& stack)
		{
			mPeek = std::move(stack.mPeek);
			mBase = stack.mBase;
			mLength = stack.mLength;

			stack.mBase = nullptr;
			stack.mLength = 0;
		}

		Stack<T>& operator=(Stack<T>&& stack)
		{
			if (this != &stack)
			{
				mPeek = std::move(stack.mPeek);
				mBase = stack.mBase;
				mLength = stack.mLength;

				mBase = nullptr;
				mLength = 0;
			}
			return *this;
		}

		Stack(Stack<T>& stack) = delete;

		Stack<T>& operator=(Stack<T>& stack) = delete;

		size_t Size() const { return mLength; }

		bool IsEmpty() const { return mLength == 0; }

		T& Peek() const
		{
			return mPeek->Data();
		}

		void Push(T data)
		{
			std::unique_ptr<Node<T>> node = std::make_unique<Node<T>>(data);
			if (IsEmpty())
			{
				mPeek = std::move(node);
				mBase = mPeek.get();
			}
			else
			{
				node->SetNextNode(std::move(mPeek));
				mPeek = std::move(node);
			}
			mLength += 1;
		}

		std::expected<T&, StackError> Pop()
		{
			if (IsEmpty)
			{
				return std::unexpected(StackError::AttemptToReadFromEmptyStack);
			}
			else
			{

			}
		}
};