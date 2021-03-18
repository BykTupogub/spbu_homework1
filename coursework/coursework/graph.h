#pragma once
#include<iostream>
#include"graph.h"



class Graph
{
private:
	int n;
	int** matrix = new int* [n];

public:
	Graph(int number, int* mat[]);

	void chengeWay(int index1, int index2, int newWay);



};
