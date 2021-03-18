#include<iostream>
#include <SFML/Graphics.hpp>
#include "Queue.h"
#include "Graph.h"
#include "map.h"


using namespace std;
using namespace sf;

void BreadthFirstSearch(Graph graph, int x1, int x2, int y1, int y2);

void Dijkstra(Graph graph);

void AStar(Graph graph);



int main(int argc, char* argv[])
{
	

	int** matrix = new int* [4];
	
	matrix[0] = new int[4]{0, 0 ,1, 0};
	matrix[1] = new int[4]{ 0, 0 ,1, 0};
	matrix[2] = new int[4]{ 1, 1, 0 ,1};
	matrix[3] = new int[4]{ 1, 1 ,0, 1};
	
	cout << endl;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << matrix[i][j]  << ' ';
		}
		cout << endl;
	}

	Image elementImage;
	if (!elementImage.loadFromFile("map.png"))
	{
		cout << "img error" << endl;
	}
	//elementImage.createMaskFromColor(Color(0, 0, 0));
	Texture map;
	map.loadFromImage(elementImage);
	Sprite s_map;
	s_map.setTexture(map);

	RenderWindow window(VideoMode(600, 600), "1");
	window.setFramerateLimit(60);
	

	Event event;
	
	
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
			
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (matrix[i][j] == 0)
					{
						s_map.setTextureRect(IntRect(0, 0, 32, 32));
					}
					if (matrix[i][j] == 1)
					{
						s_map.setTextureRect(IntRect(32, 0, 32, 32));
					}
					s_map.setPosition(j * 32, i * 32);
					window.draw(s_map);
				}
			}

			
			window.display();
		
	}
	

	/*Queue queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);*/
	
	//cout << queue << endl;
	

	return 0;
}

void BreadthFirstSearch(Graph graph, int x1, int x2, int y1, int y2)
{
}

void Dijkstra(Graph graph)
{
}

void AStar(Graph graph)
{
}
