#include<iostream>
#include "Queue.h"
#include "Graph.h"

using namespace std;

int main(int argc, char* argv[])
{
	Queue queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	
	cout << queue << endl;
	

	return 0;
}