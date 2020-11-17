#pragma once
#include<iostream>

struct Node {
public:
	int data;
	Node* next;
	Node(int data, Node* next = nullptr) :data(data), next(next) {} 
};

class LinkedList
{
private:
	int count;
	Node* head;
	Node* tail;
public:
	LinkedList() : count(0), head(nullptr), tail(nullptr) {}	
	LinkedList(const LinkedList& list);
	~LinkedList();
private:
	bool indexValid(int index);

public:
	int length();

	bool addToHead(int element);
	
	bool addToTail(int element);

	bool add(int index, int element);

	int get(int index);

	bool set(int index, int element);

	int& operator[](int index);

	friend std::ostream& operator<<(std::ostream& stream, const LinkedList list);
	
	void operator+=(int element);

	int extractHead();

	int extractTail();

	int extract(int index);

	void operator-=(int index);

	LinkedList& operator=(LinkedList list);

	int indexOf(int element);

	bool contains(int element);

}; 
