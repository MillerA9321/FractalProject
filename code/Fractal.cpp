// Include important C++ libraries here
#include <SFML/Graphics.hpp>

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
	Text text("hello, world", font, 16);
	window.draw(text);


	vector<int> xPos;
	vector<int> yPos;
	vector<int> mousePos;
	srand(1);
	int pointOneX = 300,
		pointOneY = 700,
		pointTwoX = 1000,
		pointTwoY = 700,
		pointThreeX = 650,
		pointThreeY = 50,
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

		// things we want to initialize at the start of every frame
		randomVertex = rand() % 3;

		// Clear everything from the last frame
		window.clear();

		// fractal math
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

		// Nevermind this worked fine
		for (int i = 0; i < xPos.size(); i += 1)
		{
			CircleShape shape(1);
			shape.setPosition(xPos[i], yPos[i]);
			shape.setFillColor(Color(255, 255, 255));
			window.draw(shape);
		}


		// Show everything we just drew
		window.display();


	}

	return 0;
}


