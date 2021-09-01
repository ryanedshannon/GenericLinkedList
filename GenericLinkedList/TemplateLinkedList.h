#pragma once
#include <memory>
#include <iostream>

template <typename TData>
class TemplateLinkedList {
private:
	class Node {
		TData mData;
		std::unique_ptr<Node> mNext;
		friend class TemplateLinkedList<TData>;

	public:
		Node(TData data) : mData(std::move(data)) { }

		~Node() { std::cout << "Deleting Node of data " << mData << std::endl; }
	};

	std::unique_ptr<Node> mHead;
	int mSize;

public:
	TemplateLinkedList() : mSize(0) {}
	inline int Size() const { return mSize; }\

	void PushFront(TData value) {
		auto newNode = std::make_unique<Node>(std::move(value));
		newNode->mNext = std::move(mHead);
		mHead = std::move(newNode);

		mSize++;
	}

	void PushBack(TData value) {
		auto newNode = std::make_unique<Node>(std::move(value));
		Node* temp = mHead.get();

		if (mSize == 0)
			mHead = std::move(newNode);

		else {
			while (temp->mNext != nullptr)
				temp = temp->mNext.get();

			temp->mNext = std::move(newNode);

		}

		mSize++;
	}

	void PopFront() {
		mHead = std::move(mHead->mNext);
		mSize--;
	}

	void PopBack() {
		if (mSize == 1) {
			mHead = std::move(nullptr);
		}
		else {
			Node* temp = mHead.get();

			while (temp->mNext->mNext != nullptr)
				temp = temp->mNext.get();

			temp->mNext = std::move(nullptr);
		}

		mSize--;
	}

	void Insert(int index, TData value) {
		if (index == 0)
			PushFront(std::move(value));
		else if (index == mSize - 1)
			PushBack(std::move(value));
		else {
			auto newNode = std::make_unique<Node>(std::move(value));
			Node* temp = mHead.get();

			for (int i = 0; i < index - 1; i++)
				temp = temp->mNext.get();

			if (temp->mNext != nullptr)
				newNode->mNext = std::move(temp->mNext);

			temp->mNext = std::move(newNode);
		}

		mSize++;
	}

	void RemoveAt(int index) {
		if (index < mSize) {
			Node* temp = mHead.get();

			if (index == 0) {
				PopFront();
			}
			else {
				for (int i = 0; i < index - 1; i++)
					temp = temp->mNext.get();

				temp->mNext = std::move(temp->mNext->mNext);
				mSize--;
			}
		}
	}

	int& operator[](int index) {
		Node* temp = mHead.get();

		if (index < mSize)
			for (int i = 0; i < index; i++)
				temp = temp->mNext.get();

		return temp->mData;

	}

	void Clear() {
		mHead = nullptr;
		mSize = 0;
	}

	void PrintList() const {
		std::cout << "[";
		Node* temp = mHead.get();

		while (temp != nullptr) {
			if (temp != mHead.get())
				std::cout << ", ";

			std::cout << temp->mData;
			temp = temp->mNext.get();
		}
		std::cout << "]" << std::endl;
	}
};


