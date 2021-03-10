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

void Queue::push(int data)
{
	Node* newNode = new Node(data, NULL);

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

int Queue::get()
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
	return temp->data;
}

int Queue::front()
{
	return head->data;
}

int Queue::back()
{
	return tail->data;
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
			stream << temp->data;
			if (temp->next != nullptr)
			{
				stream << ", ";
			}
			temp = temp->next;
		}
	}
	stream << "}";

	return stream;
}
