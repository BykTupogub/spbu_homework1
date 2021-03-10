#pragma once
#include<iostream>

struct Node {
public:
	int data;
	Node* next;
	Node(int data, Node* next = nullptr) :data(data), next(next) {}
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

	void push(int data);

	int get();

	int front();

	int back();

	friend std::ostream& operator<<(std::ostream& stream, const Queue queue);

};

