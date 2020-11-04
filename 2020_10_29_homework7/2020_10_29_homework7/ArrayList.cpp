#include "ArrayList.h"

ArrayList::ArrayList(const ArrayList& list)
{
	count = list.count;
	capacity = list.capacity;
	data = new int[capacity];
	for (int i = 0; i < count; ++i)
	{
		data[i] = list.data[i];
	}
}

ArrayList::~ArrayList()
{
	delete[] data;
}

void ArrayList::expand()
{
	int* newData = new int[capacity * 2];
	for (int i = 0; i < capacity; i++)
	{
		newData[i] = data[i];
	}

	capacity *= 2;
	delete[] data;
	data = newData;
}

bool ArrayList::add(int element)
{
	if (capacity == count)
	{
		expand();
	}
	data[count] = element;
	count++;
	return true;
}

bool ArrayList::add(int index, int element)
{
	if (capacity == count)
	{
		expand();
	}
	for (int i = count; i > index; --i)
	{
		data[i] = data[i - 1];
	}
	++count;
	data[index] = element;
	return true;
}

bool ArrayList::addAll(ArrayList& list)
{
	for (int i = count; i <= count + list.count; i += 2)
	{
		add(list.data[i - count]);

	}
	return true;
}

bool ArrayList::addAll(int index, ArrayList& list)
{
	if (index > count || index < 0)
	{
		return false;
	}

	for (int i = count - 1; i > index - 1; --i)
	{
		if (capacity == count)
		{
			expand();
		}
		data[i + list.count] = data[i];
	}
	for (int i = index; i < index + list.count; ++i)
	{
		data[i] = list.data[i - index];
	}
	count += list.count;
	return true;
}

void ArrayList::clear()
{
	count = 0;
}

bool ArrayList::contains(int element)
{
	for (int i = 0; i < count; ++i)
	{
		if (data[i] == element)
		{
			return true;
		}
	}
	return false;
}

int ArrayList::get(int index)
{
	if (index < 0 || index > count - 1)
	{
		return false;
	}
	return data[index];

}

bool ArrayList::set(int index, int element)
{
	if (index < 0 || index > count - 1)
	{
		return false;
	}
	data[index] = element;
	return true;
}

int ArrayList::indexOf(int element)
{
	for (int i = 0; i < count; ++i)
	{
		if (data[i] == element)
		{
			return i;
		}
	}
	return -1;
}

bool ArrayList::isEmpty()
{
	return(count == 0);
}


bool ArrayList::remove(int index)
{
	if (index < 0 || index > count - 1)
	{
		return false;
	}
	for (int i = index; i < count - 1; ++i)
	{
		data[i] = data[i + 1];
	}
	--count;
	return true;
}

bool ArrayList::swap(int index1, int index2)
{
	if (index1 < 0 || index2 < 0 || index1 > count - 1 || index2 > count - 1)
	{
		return false;
	}
	int x = data[index1];
	data[index1] = data[index2];
	data[index2] = x;
	return true;
}

int ArrayList::length()
{
	return count;
}

void ArrayList::operator+= (int item)
{
	add(item);
}

void ArrayList::operator-= (int item)
{
	remove(indexOf(item));
}

ArrayList& ArrayList::operator= (const ArrayList& list)
{
	if (&list != this)
	{
		count = list.count;
		capacity = list.capacity;
		for (int i = 0; i < count; ++i)
		{
			data[i] = list.data[i];
		}
	}
	return *this;
}

ArrayList operator+ (const ArrayList& list, int item)
{
	ArrayList a = list;
	a.add(item);
	return a;
}

ArrayList operator+ (int item, const ArrayList& list)
{
	ArrayList a = list;
	a.add(0, item);
	return a;
}

ArrayList operator+ (const ArrayList& list1, ArrayList& list2)
{
	ArrayList a = list1;
	a.addAll(list2);
	return a;
}

ArrayList operator- (const ArrayList& list, int item)
{
	ArrayList a = list;
	int x = -1;
	for (int i = 0; i < list.count; ++i)
	{
		if (list.data[i] == item)
		{
			x = i;
		}
	}
	a.remove(x);
	return a;
}

ArrayList operator- (int item, const ArrayList& list)
{
	ArrayList a = list;
	a.remove(a.indexOf(item));
	return a;
}

std::ostream& operator<<(std::ostream& stream, const ArrayList& list)
{
	stream << '[' << list.count << '/' << list.capacity << "]  {";


	for (int i = 0; i < list.count - 1; ++i)
	{
		stream << list.data[i] << ", ";
	}
	if (list.count != 0)
	{
		stream << list.data[list.count - 1];
	}
	stream << '}';
	return stream;
}

