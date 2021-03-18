#include "graph.h"

Graph::Graph(int number, int* mat[])
{
	n = number;
	//**matrix = **mat;
	for (int i = 0; i < number; ++i)
	{
		matrix[i] = new int[number];
		for (int j = 0; j < number; ++j)
		{
			matrix[i][j] = mat[i][j];
		}
	}
}

void Graph::chengeWay(int index1, int index2, int newWay)
{
}
