#include "Queue.h"
#include<iostream>

Queue::~Queue()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		Node* node = temp;
		temp = temp->next;
		delete node;
	}
}

int Queue::lenght()
{
	return count;
}

bool Queue::emphty()
{
	return count == 0;
}

bool Queue::indexValid(int index)
{
	return index >= 0 && index < count;
}

void Queue::push(int i, int j)
{
	Node* newNode = new Node(i, j, NULL);

	if (lenght() == 0)
	{
		head = tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = tail->next;
	}
	++count;
}

Node* Queue::get()
{
	Node* temp = head;
	if (head == tail)
	{
		head = tail = NULL;
	}
	else
	{
		head = head->next;
	}
	--count;
	return temp;
}

Node* Queue::front()
{
	return head;
}

Node* Queue::back()
{
	return tail;
}

std::ostream& operator<<(std::ostream& stream, const Queue queue)
{
	stream << "[" << queue.count << "]{";
	if (queue.head == nullptr)
	{
		stream << "EMPTY";
	}
	else
	{
		Node* temp = queue.head;
		while (temp != nullptr)
		{
			stream << '(' << temp->i << ", " << temp->j << " )";
			if (temp->next != nullptr)
			{
				stream << ", ";
			}
			temp = temp->next;
		}
		delete temp;
	}
	stream << "}";

	return stream;
}
