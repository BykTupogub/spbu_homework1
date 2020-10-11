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
	if (index > count || index < 0)
	{
		return false;
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
		return true;
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
	if (index >= count || index < 0)
	{
		return -1;
	}
	else
	{
		return data[index];
	}
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
	else
	{
		for (int i = index; i < count - 1; ++i)
		{
			data[i] = data[i + 1];
		}
		--count;
		return true;
	}
}

bool ArrayList::swap(int index1, int index2)
{

	if (index1 < 0 || index2 < 0 || index1 > count - 1 || index2 > count - 1)
	{
		return false;
	}
	else
	{
		int x = data[index1];
		data[index1] = data[index2];
		data[index2] = x;
		return true;
	}
}
 