#include<iostream>
#include "LinkedList.h"

using namespace std;

void printlist(LinkedList list)
{
	cout << "PRINTED LIST : " << list << endl;
}

int main()
{
	LinkedList list0;
	cout << list0 << endl;
	list0.addToHead(2);
	cout << list0 << endl;
	list0 -= 0;
	list0.addToTail(3);
	cout << list0 << endl;
	list0.add(3, 4);
	list0 -= 0;
	cout << list0 << endl;
	cout << "get 2: " << list0.get(2) << endl;
	cout << "get 5: " << list0.get(5) << endl;
	list0.set(0, 33);
	cout << "set(0, 33)" << list0 << endl;
	list0 -= 0;
	list0.set(2, 33);
	cout << "set(2 , 33)" << list0 << endl;
	cout << "list0[0] = " << list0[0] << endl;
	cout << "list0[0] = 11 : ";
	list0[0] = 11;
	cout << list0 << endl;
	list0 -= 0;
	printlist(list0);
	cout << "list1 += 555" << endl;
	list0 += 555;
	cout << list0 << endl;
	list0 -= 0;
	cout << "extractHead : " << list0.extractHead() << endl;
	cout << list0 << endl;
	cout << "extractTail : " << list0.extractTail() << endl;
	cout << list0 << endl;
	cout << "extractHead : " << list0.extract(1) << endl;
	cout << list0 << endl;
	LinkedList list3 = list0;
	cout << "list3 = list0 = " << list0 << endl;
	cout << list0.indexOf(66) << " " << list0.contains(2) << endl << endl;


	
	list0.addToHead(1);
	cout << list0 << endl;
	list0.addToHead(2);
	cout << list0 << endl;
	list0 -= 0;
	list0.addToTail(3);
	cout << list0 << endl;
	list0.add(3, 4);
	list0 -= 0;
	cout << list0 << endl;
	cout << "get 2: " << list0.get(2) << endl;
	cout << "get 5: " << list0.get(5) << endl;
	list0.set(0, 33);
	cout << "set(0, 33)" << list0 << endl;
	list0.set(2, 33);
	cout << "set(2 , 33)" << list0 << endl;
	cout << "list0[0] = " << list0[0] << endl;
	cout << "list0[0] = 11 : ";
	list0[0] = 11;
	cout << list0 << endl;
	printlist(list0);
	cout << "list1 += 555" << endl;
	list0 += 555;
	cout << list0 << endl;
	list0 -= 0;
	cout << "extractHead : " << list0.extractHead() << endl;
	cout << list0 << endl;
	list0 += 555;
	cout << "extractTail : " << list0.extractTail() << endl;
	cout << list0 << endl;
	list0 += 555;
	cout << "extract(0) : " << list0.extract(0) << endl;
	cout << list0 << endl;
	list0 += 555;
	list3 = list0;
	cout << "list3 = list0 = " << list0 << endl;
	cout << list0.indexOf(66) << " " << list0.contains(555) << endl << endl;

	LinkedList list1;
	list1.addToHead(2);
	list1.addToHead(1);
	list1.addToTail(3);
	list1.addToTail(5);
	list1.addToTail(6);
	list1.add(3, 4);
	cout << list1 << endl;
	cout << "get 2: " << list1.get(2) << endl;
	cout << "get 5: " << list1.get(5) << endl;
	list1.set(2, 33);
	cout << "set(2, 33)" << list1 << endl;
	list1.set(4, 33);
	cout << "set(4, 33)" << list1 << endl;
	cout << "list1[2] = " << list1[2] << endl;
	cout << "list1[0] = 11" << endl;
	list1[0] = 11;
	cout << list1 << endl;
	printlist(list1);
	cout << "list1 += 555" << endl;
	list1 += 555;
	cout << list1 << endl;
	cout << "extractHead : " << list1.extractHead() << endl;
	cout << list1 << endl;
	cout << "extractTail : " << list1.extractTail() << endl;
	cout << list1 << endl;
	cout << "extract(3) : " << list1.extract(3) << endl;
	cout << list1 << endl;
	LinkedList list2 = list1;
	cout << "list2 = list1 = " << list2 << endl;
	cout << list1.indexOf(66) << " " << list1.contains(2) << endl << endl;

	return 0;
}


/*продемонстрировать работу всех функций
показать, что все функции и операторы корректно работают:
1). С пустым списком.
2). Со списком из 1 элемента.
3). Со списком из нескольких элементов.
*/