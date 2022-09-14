// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	// Create a video mode object
	VideoMode vm(1280, 720);

	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game", Style::Default);

	// Load font
	Font font;
	if (!font.loadFromFile("font/times.ttf"))
	{
	}
	//Text text("hello, world", font, 16);
	//window.draw(text);

	// Trying to incorporate these
	bool vertexOne = false,
		vertexTwo = false,
		vertexThree = false;
	Vector2f clicked;
	
	// Starter fixed variables to get the fractal math correct
	vector<int> xPos;
	vector<int> yPos;
	vector<int> mousePos;
	srand(1);
	int pointOneX,
		pointOneY,
		pointTwoX,
		pointTwoY,
		pointThreeX,
		pointThreeY,
		inputX = 450,
		inputY = 400,
		tempPointX,
		tempPointY,
		randomVertex;


	while (window.isOpen())
	{

		/*
		****************************************
		Handle the players input
		****************************************
		*/

		// Show everything we just drew
		window.display();

			Event userVertexPromptOne, userVertexPromptTwo, userVertexPromptThree;
			while (!vertexThree)
			{
				if (!vertexOne)
				{
					
					while (window.pollEvent(userVertexPromptOne))
					{

						if (userVertexPromptOne.type == Event::Closed)
						{
							window.close();
						}
						if (userVertexPromptOne.type == Event::MouseButtonPressed)
						{
							if (userVertexPromptOne.mouseButton.button == Mouse::Left)
							{
								std::cout << "1the left button was pressed" << std::endl;
								std::cout << "mouse x: " << userVertexPromptOne.mouseButton.x << std::endl;
								std::cout << "mouse y: " << userVertexPromptOne.mouseButton.y << std::endl;

								clicked.x = userVertexPromptOne.mouseButton.x;
								clicked.y = userVertexPromptOne.mouseButton.y;

								pointOneX = clicked.x;
								pointOneY = clicked.y;

								vertexOne = true;
							}
						}

					}
				}
				else if (!vertexTwo)
				{
					while (window.pollEvent(userVertexPromptTwo))
					{
						if (userVertexPromptTwo.type == Event::Closed)
						{
							window.close();
						}
						if (userVertexPromptTwo.type == Event::MouseButtonPressed)
						{
							if (userVertexPromptTwo.mouseButton.button == Mouse::Left)
							{
								std::cout << "2the left button was pressed" << std::endl;
								std::cout << "mouse x: " << userVertexPromptTwo.mouseButton.x << std::endl;
								std::cout << "mouse y: " << userVertexPromptTwo.mouseButton.y << std::endl;

								clicked.x = userVertexPromptTwo.mouseButton.x;
								clicked.y = userVertexPromptTwo.mouseButton.y;

								pointTwoX = clicked.x;
								pointTwoY = clicked.y;

								vertexTwo = true;
							}
						}

					}
				}

				else if(!vertexThree)
				{
					while (window.pollEvent(userVertexPromptThree))
					{
						if (userVertexPromptThree.type == Event::Closed)
						{
							window.close();
						}
						if (userVertexPromptThree.type == Event::MouseButtonPressed)
						{
							if (userVertexPromptThree.mouseButton.button == Mouse::Left)
							{
								std::cout << "3the left button was pressed" << std::endl;
								std::cout << "mouse x: " << userVertexPromptThree.mouseButton.x << std::endl;
								std::cout << "mouse y: " << userVertexPromptThree.mouseButton.y << std::endl;

								clicked.x = userVertexPromptThree.mouseButton.x;
								clicked.y = userVertexPromptThree.mouseButton.y;

								pointThreeX = clicked.x;
								pointThreeY = clicked.y;

								vertexThree = true;
							}
						}

					}
				}
			}






		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		/*
		Make a triangle (static for now, take 3 input later)
		Take input inside of triangle
		Randomly choose one of the three points of the triangle
		Put a point at HALF the distance
		Randomly choose on of the three points of the triangle
		Repeat..

		*/

		// Variables we want to initialize at the start of every frame
		randomVertex = rand() % 3;


		// Fractal math
			if (randomVertex == 1)
			{
				tempPointX = (inputX + pointOneX) / 2;
				tempPointY = (inputY + pointOneY) / 2;

				xPos.push_back(tempPointX);
				yPos.push_back(tempPointY);
				inputX = tempPointX;
				inputY = tempPointY;
			}
			else if (randomVertex == 2)
			{
				tempPointX = (inputX + pointTwoX) / 2;
				tempPointY = (inputY + pointTwoY) / 2;

				xPos.push_back(tempPointX);
				yPos.push_back(tempPointY);
				inputX = tempPointX;
				inputY = tempPointY;
			}
			else
			{
				tempPointX = (inputX + pointThreeX) / 2;
				tempPointY = (inputY + pointThreeY) / 2;

				xPos.push_back(tempPointX);
				yPos.push_back(tempPointY);
				inputX = tempPointX;
				inputY = tempPointY;
			}

			// Clear everything from the last frame
			window.clear();

			// Nevermind this worked fine
			for (int i = 0; i < xPos.size(); i += 1)
			{
				CircleShape shape(1);
				shape.setPosition(xPos[i], yPos[i]);
				shape.setFillColor(Color(255, 255, 255));
				window.draw(shape);
			}

		

	}

	return 0;
}


