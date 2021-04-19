#pragma once
#include<iostream>
#include"graph.h"



class Graph
{
private:
	int n;
	struct Point
	{
		int visited = 0;
		//посещениие из
		// 0 - не посещено
		// 1 - из верхней
		// 2 - из нижней
		// 3 - из правой
		// 4 - из левой

		int value = 0;
	};

public:
	Point** matrix;

	Graph(int number, int* mat[]);

	~Graph();

	int size();

	void chengeWay(int i, int j, int newWay);

	int getValue(int i, int j);

	int getVisited(int i, int j);

	bool indexValid(int i, int j);

	void chengeVisit(int i, int j, int visit);

	void print();

	void printVisit();

	void randBin();

	bool abilityToMove(int i, int j);

	

};
