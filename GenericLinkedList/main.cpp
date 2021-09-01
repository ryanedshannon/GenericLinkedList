#include "TemplateLinkedList.h"
#include <memory>
#include <iostream>
#include <string>

using namespace std;

int main() {
	int r;
	TemplateLinkedList<int> s;
	s.PushBack(3);
	s.PushFront(2);
	s.PushBack(4);
	s.PushFront(1);
	s.PushBack(5);
	s.PopFront();
	s.PopBack();

	TemplateLinkedList<string> s2;
	s2.PushBack("Hello!");
	s2.PushFront("Goodbye!");
	s2.PushBack("I have terminal cancer");
	s2.Insert(1, "hi");
	s.PrintList();
	s2.PrintList();
	
	TemplateLinkedList<unique_ptr<string>> s3;
	s3.PushFront(make_unique<string>("fuk"));
	s3.PushBack(make_unique<string>("hewoo"));
	s3.PushBack(make_unique<string>("owo"));
	s3.Insert(2, (make_unique<string>("bruh")));
	s3.RemoveAt(2);
	s3.PopBack();
	s3.PopFront();
	s3.Size();
	s3.PrintList();
	cin >> r;
}