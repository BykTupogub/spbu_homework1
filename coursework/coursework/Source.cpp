#include<iostream>
#include <SFML/Graphics.hpp>
#include "Queue.h"
#include "Graph.h"
#include "map.h"
#include <ctime>
#include <dos.h>
#include "windows.h"


using namespace std;
using namespace sf;

void pathBuilding(Graph& graph, int x1, int y1, int x2, int y2);

void BreadthFirstSearch(Graph& graph, int x1, int y1, int x2, int y2);

void pathBuildingDiagonal(Graph& graph, int x1, int y1, int x2, int y2);

void BreadthFirstSearchDiagonal(Graph& graph, int x1, int y1, int x2, int y2);

void Dijkstra(Graph graph);

void AStar(Graph graph);




int main(int argc, char* argv[])
{
	//srand(time(0));

	int** templateMatrix = new int* [10];
	templateMatrix[0] = new int[10]{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	templateMatrix[1] = new int[10]{ 0, 0, 1, 1, 1, 1, 0, 1, 1, 0 };
	templateMatrix[2] = new int[10]{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 0 };
	templateMatrix[3] = new int[10]{ 1, 0, 1, 0, 1, 1, 1, 1, 0, 1 };
	templateMatrix[4] = new int[10]{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 };
	templateMatrix[5] = new int[10]{ 0, 0, 1, 0, 0, 1, 1, 0, 1, 1 };
	templateMatrix[6] = new int[10]{ 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 };
	templateMatrix[7] = new int[10]{ 0, 1, 1, 0, 0, 0, 0, 1, 1, 0 };
	templateMatrix[8] = new int[10]{ 0, 0, 0, 0, 1, 1, 0, 1, 0, 0 };
	templateMatrix[9] = new int[10]{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 };

	int** templateMatrix1 = new int* [10];
	templateMatrix1[0] = new int[10]{ 1, 7, 7, 7, 7, 7, 2, -10, -10, -10 };
	templateMatrix1[1] = new int[10]{ 5, 1, 7, 7, 4, 7, 2, 1, 11, -10 };
	templateMatrix1[2] = new int[10]{ 1, 5, 7, 7, 7, 7, 7, 1, 11, -10 };
	templateMatrix1[3] = new int[10]{ 1, 5, 5, 5, 1, 1, 1, 1, 1, 1 };
	templateMatrix1[4] = new int[10]{ 1, 5, 5, 1, 7, 7, 5, 5, 5, 5 };
	templateMatrix1[5] = new int[10]{ 1, 5, 1, 4, 10, 7, 5, 5, 1, 1 };
	templateMatrix1[6] = new int[10]{ 1, 1, 5, 10, 10, 5, 5, 5, 5, 3 };
	templateMatrix1[7] = new int[10]{ 5, 5, 5, -10, 10, 5, 11, 11, 11, 5 };
	templateMatrix1[8] = new int[10]{ 5, 2, 5, 3, 1, 1, 2, 2, 5, 5 };
	templateMatrix1[9] = new int[10]{ 3, 2, 5, 5, 5, 1, 2, 2, 5, 5 };

	/*
		int** matrix = new int* [10];
		for (int i = 0; i < 10; ++i)
		{
			matrix[i] = new int[10];
			for (int j = 0; j < 10; ++j)
			{
				matrix[i][j] = 0;
			}
		}
	*/


	Graph mat(10, templateMatrix);
	//mat.randBin();
	
	
	BreadthFirstSearch(mat, 0, 0, 9, 9);

	Graph mat1(10, templateMatrix);

	BreadthFirstSearchDiagonal(mat1, 0, 0, 9, 9);

	
	
	for (int i = 0; i < 10; ++i)
	{
		delete[] templateMatrix[i];
	}
	delete[] templateMatrix;


		return 0;
	}

void pathBuilding(Graph& graph, int x1, int y1, int x2, int y2)
{
	while (x2 != x1 || y2 != y1)
	{
		switch (graph.getVisited(y2, x2))
		{
		case 9:
		{
			graph.chengeVisit(y1, x2, 6);
			++y2;
			break;
		}
		case 10:
		{
			graph.chengeVisit(y2, x2, 6);
			--y2;
			break;
		}
		case 7:
		{
			graph.chengeVisit(y2, x2, 6);
			--x2;
			break;
		}
		case 8:
		{
			graph.chengeVisit(y2, x2, 6);
			++x2;
			break;
		}
		default:
			break;
		}
	}
}

void BreadthFirstSearch(Graph& graph, int x1, int y1, int x2, int y2)
{

	Image elementImage;
	if (!elementImage.loadFromFile("img/map.png"))
	{
		cout << "img error" << endl;
	}

	Texture map;
	map.loadFromImage(elementImage);
	Sprite s_map;
	s_map.setTexture(map);

	RenderWindow window(VideoMode(600, 600), "BreadthFirstSearch");
	window.setFramerateLimit(60);


	Event event;


	Queue queue;
	queue.push(0, 0);
	Node* temp = queue.get();
	graph.chengeVisit(0, 0, 6);
	int F = 0;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
			{
				window.close();
			}

		}
		window.clear();
		if (F == 0)
		{
			for (int i = 0; i < graph.size(); ++i)
			{
				for (int j = 0; j < graph.size(); ++j)
				{
					if (graph.getVisited(i, j) != 0)
					{
						s_map.setTextureRect(IntRect(graph.getVisited(i, j) * 32, 0, 32, 32));
					}

					else if (graph.getValue(i, j) == 0)
					{
						s_map.setTextureRect(IntRect(0, 0, 32, 32));
					}
					else if (graph.getValue(i, j) == 1)
					{
						s_map.setTextureRect(IntRect(32, 0, 32, 32));
					}

					s_map.setPosition(j * 32, i * 32);
					window.draw(s_map);
				}

			}
			s_map.setTextureRect(IntRect(32*6, 0, 32, 32));
			s_map.setPosition(9 * 32, 9 * 32);
			window.draw(s_map);
		}

		if (F == 1)
		{
			for (int i = 0; i < graph.size(); ++i)
			{
				for (int j = 0; j < graph.size(); ++j)
				{
					if (graph.getVisited(i, j) == 6)
					{
						s_map.setTextureRect(IntRect(6 * 32, 0, 32, 32));
					}

					else if (graph.getValue(i, j) == 0)
					{
						s_map.setTextureRect(IntRect(0, 0, 32, 32));
					}
					else if (graph.getValue(i, j) == 1)
					{
						s_map.setTextureRect(IntRect(32, 0, 32, 32));
					}

					s_map.setPosition(j * 32, i * 32);
					window.draw(s_map);
				}
			}
		}



		if (F == 0)
		{
			if (graph.abilityToMove(temp->i, temp->j + 1) && graph.getVisited(temp->i, temp->j + 1) == 0)
			{
				queue.push(temp->i, temp->j + 1);
				graph.chengeVisit(temp->i, temp->j + 1, 7);

				cout << endl;
				graph.printVisit();
				cout << temp->i << ", " << temp->j << endl;
				cout << endl;
				if (temp->i == x2 && temp->j + 1 == y2)
				{
					F = 1;
				}
			}

			if (graph.abilityToMove(temp->i, temp->j - 1) && graph.getVisited(temp->i, temp->j - 1) == 0)
			{
				queue.push(temp->i, temp->j - 1);
				graph.chengeVisit(temp->i, temp->j - 1, 8);

				cout << endl;
				graph.printVisit();
				cout << temp->i << ", " << temp->j << endl;
				cout << endl;
				if (temp->i == x2 && temp->j - 1 == y2)
				{
					F = 1;
				}
			}

			if (graph.abilityToMove(temp->i + 1, temp->j) && graph.getVisited(temp->i + 1, temp->j) == 0)
			{
				queue.push(temp->i + 1, temp->j);
				graph.chengeVisit(temp->i + 1, temp->j, 10);

				cout << endl;
				graph.printVisit();
				cout << temp->i << ", " << temp->j << endl;
				cout << endl;
				if (temp->i + 1 == x2 && temp->j == y2)
				{
					F = 1;
				}
			}

			if (graph.abilityToMove(temp->i - 1, temp->j) && graph.getVisited(temp->i - 1, temp->j) == 0)
			{
				queue.push(temp->i - 1, temp->j);
				graph.chengeVisit(temp->i - 1, temp->j, 9);

				cout << endl;
				graph.printVisit();
				cout << temp->i << ", " << temp->j << endl;
				cout << endl;
				if (temp->i - 1 == x2 && temp->j == y2)
				{
					F = 1;
				}
			}

			if (queue.emphty())
			{
				F = -1;
			}
			else
			{
				temp = queue.get();
			}
			if (F == 1)
			{
				pathBuilding(graph, x1, y1, x2, y2);
				cout << endl << x2 << " " << y2 << endl;
				Sleep(2000);
			}
		}

		Sleep(100);

		window.display();
	}
}

void pathBuildingDiagonal(Graph& graph, int x1, int y1, int x2, int y2)
{
	while (x2 != x1 || y2 != y1)
	{
		switch (graph.getVisited(y2, x2))
		{
		case 9:
		{
			graph.chengeVisit(y2, x2, 6);
			++y2;
			break;
		}
		case 10:
		{
			graph.chengeVisit(y2, x2, 6);
			--y2;
			break;
		}
		case 7:
		{
			graph.chengeVisit(y2, x2, 6);
			--x2;
			break;
		}
		case 8:
		{
			graph.chengeVisit(y2, x2, 6);
			++x2;
			break;
		}
		case 11:
		{
			graph.chengeVisit(y2, x2, 6);
			--y2;
			--x2;
			break;
		}
		case 12:
		{
			graph.chengeVisit(y2, x2, 6);
			++y2;
			--x2;
			break;
		}
		case 13:
		{
			graph.chengeVisit(y2, x2, 6);
			--y2;
			++x2;
			break;
		}
		case 14:
		{
			graph.chengeVisit(y2, x2, 6);
			++y2;
			++x2;
			break;
		}
		default:
			break;
		}
	}
}

void BreadthFirstSearchDiagonal(Graph& graph, int x1, int y1, int x2, int y2)
{

	Image elementImage;
	if (!elementImage.loadFromFile("img/map.png"))
	{
		cout << "img error" << endl;
	}

	Texture map;
	map.loadFromImage(elementImage);
	Sprite s_map;
	s_map.setTexture(map);

	RenderWindow window(VideoMode(600, 600), "BreadthFirstSearchDiagonal");
	window.setFramerateLimit(60);


	Event event;


	Queue queue;
	queue.push(0, 0);
	Node* temp = queue.get();
	graph.chengeVisit(0, 0, 6);
	int F = 0;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
			{
				window.close();
			}

		}
		window.clear();
		if (F == 0)
		{
			for (int i = 0; i < graph.size(); ++i)
			{
				for (int j = 0; j < graph.size(); ++j)
				{
					if (graph.getVisited(i, j) != 0)
					{
						s_map.setTextureRect(IntRect(graph.getVisited(i, j) * 32, 0, 32, 32));
					}

					else if (graph.getValue(i, j) == 0)
					{
						s_map.setTextureRect(IntRect(0, 0, 32, 32));
					}
					else if (graph.getValue(i, j) == 1)
					{
						s_map.setTextureRect(IntRect(32, 0, 32, 32));
					}

					s_map.setPosition(j * 32, i * 32);
					window.draw(s_map);
				}

			}
			s_map.setTextureRect(IntRect(32 * 6, 0, 32, 32));
			s_map.setPosition(9 * 32, 9 * 32);
			window.draw(s_map);
		}

		if (F == 1)
		{
			for (int i = 0; i < graph.size(); ++i)
			{
				for (int j = 0; j < graph.size(); ++j)
				{
					if (graph.getVisited(i, j) == 6)
					{
						s_map.setTextureRect(IntRect(6 * 32, 0, 32, 32));
					}

					else if (graph.getValue(i, j) == 0)
					{
						s_map.setTextureRect(IntRect(0, 0, 32, 32));
					}
					else if (graph.getValue(i, j) == 1)
					{
						s_map.setTextureRect(IntRect(32, 0, 32, 32));
					}

					s_map.setPosition(j * 32, i * 32);
					window.draw(s_map);
				}
			}
		}



		if (F == 0)
		{
			if (graph.abilityToMove(temp->i, temp->j + 1) && graph.getVisited(temp->i, temp->j + 1) == 0)
			{
				queue.push(temp->i, temp->j + 1);
				graph.chengeVisit(temp->i, temp->j + 1, 7);

				cout << endl;
				graph.printVisit();
				cout << temp->i << ", " << temp->j << endl;
				cout << endl;
				if (temp->i == x2 && temp->j + 1 == y2)
				{
					F = 1;
				}
			}

			if (graph.abilityToMove(temp->i, temp->j - 1) && graph.getVisited(temp->i, temp->j - 1) == 0)
			{
				queue.push(temp->i, temp->j - 1);
				graph.chengeVisit(temp->i, temp->j - 1, 8);

				cout << endl;
				graph.printVisit();
				cout << temp->i << ", " << temp->j << endl;
				cout << endl;
				if (temp->i == x2 && temp->j - 1 == y2)
				{
					F = 1;
				}
			}

			if (graph.abilityToMove(temp->i + 1, temp->j) && graph.getVisited(temp->i + 1, temp->j) == 0)
			{
				queue.push(temp->i + 1, temp->j);
				graph.chengeVisit(temp->i + 1, temp->j, 10);

				cout << endl;
				graph.printVisit();
				cout << temp->i << ", " << temp->j << endl;
				cout << endl;
				if (temp->i + 1 == x2 && temp->j == y2)
				{
					F = 1;
				}
			}

			if (graph.abilityToMove(temp->i - 1, temp->j) && graph.getVisited(temp->i - 1, temp->j) == 0)
			{
				queue.push(temp->i - 1, temp->j);
				graph.chengeVisit(temp->i - 1, temp->j, 9);

				cout << endl;
				graph.printVisit();
				cout << temp->i << ", " << temp->j << endl;
				cout << endl;
				if (temp->i - 1 == x2 && temp->j == y2)
				{
					F = 1;
				}
			}

			if (graph.abilityToMove(temp->i + 1, temp->j + 1) && graph.getVisited(temp->i + 1, temp->j + 1) == 0)
			{
				queue.push(temp->i + 1, temp->j + 1);
				graph.chengeVisit(temp->i + 1, temp->j + 1, 11);

				cout << endl;
				graph.printVisit();
				cout << temp->i << ", " << temp->j << endl;
				cout << endl;
				if (temp->i + 1 == x2 && temp->j + 1 == y2)
				{
					F = 1;
				}
			}

			if (graph.abilityToMove(temp->i + 1, temp->j - 1) && graph.getVisited(temp->i + 1, temp->j - 1) == 0)
			{
				queue.push(temp->i + 1, temp->j - 1);
				graph.chengeVisit(temp->i + 1, temp->j - 1, 13);

				cout << endl;
				graph.printVisit();
				cout << temp->i << ", " << temp->j << endl;
				cout << endl;
				if (temp->i + 1 == x2 && temp->j - 1 == y2)
				{
					F = 1;
				}

			}

			if (graph.abilityToMove(temp->i - 1, temp->j + 1) && graph.getVisited(temp->i - 1, temp->j + 1) == 0)
			{
				queue.push(temp->i - 1, temp->j + 1);
				graph.chengeVisit(temp->i - 1, temp->j + 1, 12);

				cout << endl;
				graph.printVisit();
				cout << temp->i << ", " << temp->j << endl;
				cout << endl;
				if (temp->i - 1 == x2 && temp->j + 1 == y2)
				{
					F = 1;
				}
			}

			if (graph.abilityToMove(temp->i - 1, temp->j - 1) && graph.getVisited(temp->i - 1, temp->j - 1) == 0)
			{
				queue.push(temp->i - 1, temp->j - 1);
				graph.chengeVisit(temp->i - 1, temp->j - 1, 14);

				cout << endl;
				graph.printVisit();
				cout << temp->i << ", " << temp->j << endl;
				cout << endl;
				if (temp->i - 1 == x2 && temp->j - 1 == y2)
				{
					F = 1;
				}
			}

			if (F == 1)
			{
				pathBuildingDiagonal(graph, x1, y1, x2, y2);
				Sleep(2000);
			}
			else if (queue.emphty())
			{
				F = -1;
			}
			else
			{
				temp = queue.get();
			}
			
		}

		Sleep(100);

		window.display();
	}
}

void Dijkstra(Graph graph)
{
}

void AStar(Graph graph)
{
}


