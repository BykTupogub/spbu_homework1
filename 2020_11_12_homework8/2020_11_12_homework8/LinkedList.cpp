#include "LinkedList.h"

LinkedList::LinkedList(const LinkedList& list)
{
	tail = head = nullptr;
	count = 0;

	Node* temp = list.head;
	while (temp != nullptr)
	{
		addToTail(temp->data);
		temp = temp->next;
	}

}

LinkedList::~LinkedList()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		Node* node = temp;
		temp = temp->next;
		delete node;
	}
}

bool LinkedList::indexValid(int index)
{
	return index >= 0 && index < count;
}

int LinkedList::length()
{
	return count;
}

bool LinkedList::addToHead(int element)
{
	if (head == nullptr)
	{
		head = tail = new Node(element);
	}
	else
	{
		head = new Node(element, head);
	}
	++count;
	return true;
}

bool LinkedList::addToTail(int element)
{
	if (head == nullptr)
	{
		head = tail = new Node(element);
	}
	else
	{
		tail->next = new Node(element);
		tail = tail->next;
	}
	++count;
	return true;
	
}

bool LinkedList::add(int index, int element)
{
	if (index == 0)
	{
		return addToHead(element);
	}
	if (index == count)
	{
		return addToTail(element);
	}
	if (!indexValid(index))
	{
		return false;
	}

	Node* temp = head;
	while (index > 1)
	{
		temp = temp->next;
		--index;
	}
	temp->next = new Node(element, temp->next);
	++count;

	return true;
}

int LinkedList::get(int index)
{
	if (!indexValid(index))
	{
		return -1;
	}
	if (index == 0)
	{
		return head->data;
	}
	if (index == count - 1)
	{
		return tail->data;
	}

	Node* temp = head;
	for (int i = 0; i < index; ++i)
	{
		temp = temp->next;
	}
	return temp->data;
}

bool LinkedList::set(int index, int element)
{
	if (!indexValid(index))
	{
		return false;
	}
	if (index == 0)
	{
		head->data = element;
	}
	else if (index == count - 1)
	{
		tail->data = element;
	}
	else
	{

		Node* temp = head;
		for (int i = 0; i < index; ++i)
		{
			temp = temp->next;
		}
		temp->data = element;

	}
	return true;
}

int& LinkedList::operator[](int index)
{
	if (head == nullptr)
	{
		addToHead(0);
		return head->data;
	}
	if (index <= 0)
	{
		return head->data;
	}
	if (index >= count)
	{
		addToTail(0);
		return tail->data;
	}
	if (index == count - 1)
	{
		return tail->data;
	}

	Node* temp = head;
	for (int i = 0; i < index; ++i)
	{
		temp = temp->next;
	}
	return temp->data;
}

void LinkedList::operator+=(int element)
{
	addToTail(element);
}

int LinkedList::extractHead()
{
	if (head == nullptr)
	{
		return -1;
	}	
	Node* temp = head;
	head = head->next;
	int x = temp->data;
	delete temp;
	--count;
	return x;

}

int LinkedList::extractTail()
{
	if (head == nullptr)
	{
		return -1;
	}
	if (count == 1)
	{
		Node* temp = tail;
		head = tail = nullptr;
		int x = temp->data;
		delete temp;
		--count;
		return x;
	}
	Node* temp = head;
	while (temp->next != tail)
	{
		temp = temp->next;
	}
	tail = temp;
	temp = temp->next;
	int x = temp->data;
	delete temp;
	tail->next = nullptr;
	--count;
	return x;
}

int LinkedList::extract(int index)
{

	if (!indexValid(index))
	{
		return -1;
	}
	if (index == 0)
	{
		return extractHead();
	}
	if (index == count - 1)
	{
		return extractTail();
	}
	
	Node* temp = head;
	while (index > 1)
	{
		temp = temp->next;
		--index;
	}
	Node* node = temp;
	temp = temp->next;
	node->next = temp->next;
	int x = temp->data;
	delete temp;
	--count;
	return x;
}

void LinkedList::operator-=(int index)
{
	extract(index);
}

LinkedList& LinkedList::operator=(LinkedList list)
{
	if (&list != this)
	{
		Node* temp = list.head;
		count = 0;
		while (temp != nullptr)
		{
			addToTail(temp->data);
			temp = temp->next;
		}
		delete temp;
	}
	return *this;
}

int LinkedList::indexOf(int element)
{ 
	Node* temp = head;
	for (int i = 0; i < count; ++i)
	{
		if (temp->data == element)
		{
			return i; 
		}
		temp = temp->next;
	}
	return -1;
}

bool LinkedList::contains(int element)
{
	return indexOf(element) != -1;
}

std::ostream& operator<<(std::ostream& stream, const LinkedList list)
{
	stream << "[" << list.count << "]{";
	if (list.head == nullptr)
	{
		stream << "EMPTY";
	}
	else
	{
		Node* temp = list.head;
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
