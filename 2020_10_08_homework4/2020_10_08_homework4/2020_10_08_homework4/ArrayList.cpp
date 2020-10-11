#include"ArrayList.h"

ArrayList::ArrayList()
{
	capacity = 10;
	count = 0;
	data = new int[10];
}

ArrayList::ArrayList(int cap)
{
	capacity = cap;
	count = 0;
	data = new int[cap];
}

ArrayList::~ArrayList()
{
	delete[] data;
}

void ArrayList::print()
{
	cout << "[" << count << "/" << capacity << "]";
	if (count == 0)
	{
		cout << "EMPTY";
	}
	else
	{
		for (int i = 0; i < count; ++i)
		{
			cout << data[i] << (i == count - 1 ? "" : ", ");
		}
	}
	cout << "}\n";
}

void expandArray(int*& data, int& capacity)
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

 void ArrayList::add(int element)
{
	if (capacity == count)
	{
		expandArray(data, capacity);
	}
	data[count] = element;
	count++;
}

void ArrayList::add(int index, int element)
{
	if (capacity == count)
	{
		expandArray(data, capacity);
	}
	for (int i = count; i > index; --i)
	{
		data[i] = data[i - 1];
	}
	++count;
	data[index] = element;
}


void ArrayList::addAll(ArrayList& list)
{
	for (int i = count; i < count + list.count; ++i)
	{
		if (capacity == count)
		{
			expandArray(data, capacity);
		}
		data[i] = list.data[i - count];
	}
	count += list.count;

}

bool ArrayList::addAll(int index, ArrayList& list)
{
	bool returns = false;
	if (index > count || index < 0)
	{
		return returns;
	}
	else
	{
		for (int i = count - 1; i > index - 1; --i)
		{
			if (capacity == count)
			{
				expandArray(data, capacity);
			}
			data[i + list.count] = data[i];
		}
		for (int i = index; i < index + list.count; ++i)
		{
			data[i] = list.data[i - index];
		}
		count += list.count;
		returns = true;
		return returns;
	}
}


void ArrayList::clear()
{
	for (int i = 0; i < count; ++i)
	{
		data[i] = 0;
	}
}

bool ArrayList::contains(int element)
{
	bool returns = false;
	for (int i = 0; i < count; ++i)
	{
		if (data[i] == element)
		{
			returns = true;
		}
	}
	return returns;
}

int ArrayList::get(int index)
{
	int returns = -1;
	if (index >= count || index < 0)
	{
		return returns;
	}
	else
	{
		returns = data[index];
		return returns;
	}
}

int ArrayList::indexOf(int element)
{
	int returns = -1;
	for (int i = 0; i < count; ++i)
	{
		if (data[i] == element) 
		{
			returns = i;
			return returns;
		}
	}
	return returns;
}

bool ArrayList::isEmpty()
{
	bool returns = false;
	for (int i = 0; i < count; ++i)
	{
		if (data[i] != 0)
		{
			returns = true;
		}
	}
	return returns;
}

bool ArrayList::remove(int index) 
{
	bool returns = false;
	if (index < 0 || index > count - 1)
	{
		return returns;
	}
	else
	{
		for (int i = index; i < count - 1; ++i)
		{
			data[i] = data[i + 1];
		}
		--count;
		returns = true;
		return returns;
	}
}

bool ArrayList::swap(int index1, int index2)
{
	bool returns = false;
	if (index1 < 0 || index2 < 0 || index1 > count - 1 || index2 > count - 1)
	{
		return returns;
	}
	else
	{
		int x = data[index1];
		data[index1] = data[index2];
		data[index2] = x;
		returns = true;
		return returns;
	}
}
 