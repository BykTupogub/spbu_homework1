#include "ArrayList.h"

ArrayList::~ArrayList()
{
	if (str != nullptr)
	{
		delete[] str;
	}
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

int ArrayList::numLength(int number)
{
	int result = 1;
	if (number < 0)
	{
		number *= -1;
		++result;
	}
	while (number > 9)
	{
		number /= 10;
		++result;
	}
	return result;
}

void ArrayList::addSymbolToStr(int& index, char symbol)
{
	str[index] = symbol;
	++index;
}

void ArrayList::addNumberToStr(int& index, int number)
{
	int length = numLength(number);
	if (number < 0)
	{
		number *= -1;
		str[index] = '-';
		index++;
		--length;
	}
	for (int i = 0; i < length; ++i)
	{
		int digit = number % 10;
		str[index + length - 1 - i] = '0' + digit;
		number /= 10;
	}
	
	index += length;
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
	for (int i = count; i < count + list.count; i += 2)
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

char* ArrayList::toString()
{
	if (str != nullptr)
	{
		delete[] str;
		str = nullptr;
	}
	int length = 5 + numLength(count) + numLength(capacity);
	for (int i = 0; i < count; ++i)
	{
		length = length + numLength(data[i]) + 2;
	}
	str = new char[length];
	int index = 0;
	addSymbolToStr(index, '[');
	addNumberToStr(index, count);
	addSymbolToStr(index, '/');
	addNumberToStr(index, capacity);
	addSymbolToStr(index, ']');
	addSymbolToStr(index, ' ');
	addSymbolToStr(index, '{');

	for (int i = 0; i < count - 1; ++i)
	{
		addNumberToStr(index, data[i]);
		addSymbolToStr(index, ',');
		addSymbolToStr(index, ' ');
	}
	addNumberToStr(index, data[count - 1]);
	addSymbolToStr(index, '}');
	addSymbolToStr(index, '\0');

	return str;
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
