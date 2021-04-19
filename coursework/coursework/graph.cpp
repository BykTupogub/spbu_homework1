#include "graph.h"
#include <ctime>



Graph::Graph(int number, int* mat[])
{

	n = number;
	//**matrix = **mat;
	matrix = new Point * [n];
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new Point[n];
		for (int j = 0; j < number; ++j)
		{
			matrix[i][j].value = mat[i][j];
		}
	}
}

Graph::~Graph()
{	
	for (int i = 0; i < n; ++i)
	{
		delete [] matrix[i];
	}
	delete[] matrix;
}

int Graph::size()
{
	return n;
}

void Graph::chengeWay(int i, int j, int newWay)
{
	matrix[i][j].value = newWay;
}

int Graph::getValue(int i, int j)
{
	return matrix[i][j].value;
}

int Graph::getVisited(int i, int j)
{
	return matrix[i][j].visited;
}

bool Graph::indexValid(int i, int j)
{
	return (i < n && i >= 0 && j < n && j >= 0);
}

void Graph::chengeVisit(int i, int j, int visit)
{
	matrix[i][j].visited = visit;
}


void Graph::print()
{
	for (int i = 0; i < n; ++i)
	{
		
		for (int j = 0; j < n; ++j)
		{
			std::cout << matrix[i][j].value << " ";
		}
		std::cout << std::endl;
	}
}

void Graph::printVisit()
{
	for (int i = 0; i < n; ++i)
	{

		for (int j = 0; j < n; ++j)
		{
			std::cout << matrix[i][j].visited << " ";
		}
		std::cout << std::endl;
	}
}

void Graph::randBin()
{
	
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new Point[n];
		for (int j = 0; j < n; ++j)
		{
			if ((rand() % 10) == 0 || (rand() % 10) == 1)
			{
				matrix[i][j].value = 1;
			}
			else
			{
				matrix[i][j].value = 0;
			}
		}
	}
}

bool Graph::abilityToMove(int i, int j)
{
	if (indexValid(i, j) && matrix[i][j].value == 0)
	{
		return true;
	}
	return false;
	
}




