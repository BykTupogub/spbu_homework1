#pragma once
#include<iostream>

struct Node {
public:
	int i;
	int j;
	Node* next;
	Node(int i, int j, Node* next = nullptr) :i(i), j(j), next(next) {}
};


class Queue
{
private:
	int count;
	Node* head;
	Node* tail;
public:

	Queue() : count(0), head(nullptr), tail(nullptr) {}

	~Queue();

	int lenght();

	bool emphty();

	bool indexValid(int index);

	void push(int i, int j);

	Node* get();

	Node* front();

	Node* back();

	friend std::ostream& operator<<(std::ostream& stream, const Queue queue);

};

