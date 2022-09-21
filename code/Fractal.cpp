// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	// Create a video mode object, in this case a 720p window
	VideoMode vm(1280, 720);

	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game", Style::Default);

	// Load font and throw console error if font file not found
	Font font;
	if (!font.loadFromFile("font/times.ttf"))
	{
		std::cout << "Error: Font File" << std::endl;
	}

	//Declaration chunk, these are all used throughout different parts of the program so decaring them here makes it easier than redclaring in several loops. 
	bool vertexOne = false,
		 vertexTwo = false,
		 vertexThree = false,
		 initialPoint = false;

	vector<int> xPos,
				yPos,
				mousePos;

	int pointOneX,
		pointOneY,
		pointTwoX,
		pointTwoY,
		pointThreeX,
		pointThreeY,
		inputX,
		inputY,
		randomVertex;

	//Init random so that random Verticies can be chosen
	srand(1);

	//Open the window and begin the loop(s)
	while (window.isOpen())
	{

		/*
		****************************************
		Handle the players input
		****************************************
		*/

		// This fixed the white screen bug and I couldn't tell you why
		window.display();

			//Declare all of the user input variables
			Event userVertexPromptOne,
				  userVertexPromptTwo,
				  userVertexPromptThree,
				  initialPointPrompt;

			//Declare all of the shapes that are referenced during input
			CircleShape vertexOneIndicator(5),
						vertexTwoIndicator(5),
						vertexThreeIndicator(5),
						initialPointIndicator(5);

			//Move the shapes so that they dont stack in the default position (top left)
			vertexOneIndicator.setPosition(-100, -100);
			vertexTwoIndicator.setPosition(-100, -100);
			vertexThreeIndicator.setPosition(-100, -100);
			initialPointIndicator.setPosition(-100, -100);

			//Decalre all of the text that is referenced during input
			Text vertexOneText("Click vertex one location", font, 30);
			Text vertexTwoText("Click vertex two location", font, 30);
			Text vertexThreeText("Click vertex three location", font, 30);
			Text initialPointText("Click starting point location", font, 30);

			//Center text for more convienient reading
			vertexOneText.setPosition(480, 0);
			vertexTwoText.setPosition(480, 0);
			vertexThreeText.setPosition(480, 0);
			initialPointText.setPosition(480, 0);

			//Start the loop to take users input while stopping the program from deciding it really needs to do the math before the variable is actually filled
			while (!initialPoint)
			{
				//This handles player click inputs. Used for storing X and Y coordinates in the vectors. Declared here because it is used throughout this loop and this loop only.
				Vector2f clicked;

				//Gets user input for vertex one and verifies which point it gets through console using a number
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
							//Essentially gets position of mouse click and sanity checks by saying in console which click was taken and where it was
							if (userVertexPromptOne.mouseButton.button == Mouse::Left)
							{
								//This is the sanity check (this code was demonstrated in class)
								std::cout << "The first point is taken" << std::endl;
								std::cout << "mouse x: " << userVertexPromptOne.mouseButton.x << std::endl;
								std::cout << "mouse y: " << userVertexPromptOne.mouseButton.y << std::endl;

								//Store user click position
								pointOneX = userVertexPromptOne.mouseButton.x;
								pointOneY = userVertexPromptOne.mouseButton.y;

								//Set the indicator shape position to the click position and set its color to differentiate
								vertexOneIndicator.setPosition(pointOneX, pointOneY);
								vertexOneIndicator.setFillColor(Color(255, 0, 0));

								//Set the bool vertex check to true in order to progress to the next point
								vertexOne = true;
							}
						}

						// This group of code clears the previous frame, stops text from stacking, and then prints the corresponding indicator (red dot) and text 
						window.clear();
						window.draw(vertexOneIndicator);
						window.draw(vertexOneText);
						window.display();
					}
				}
				//Repeat for vertex two
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
								std::cout << "The second point is taken" << std::endl;
								std::cout << "mouse x: " << userVertexPromptTwo.mouseButton.x << std::endl;
								std::cout << "mouse y: " << userVertexPromptTwo.mouseButton.y << std::endl;

								pointTwoX = userVertexPromptTwo.mouseButton.x;
								pointTwoY = userVertexPromptTwo.mouseButton.y;

								vertexTwoIndicator.setPosition(pointTwoX, pointTwoY);
								vertexTwoIndicator.setFillColor(Color(255, 0, 0));

								vertexTwo = true;
							}
						}
						window.clear();
						window.draw(vertexOneIndicator);
						window.draw(vertexTwoIndicator);
						window.draw(vertexTwoText);
						window.display();

					}
				}
				//Repeat for vertex three
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
								std::cout << "The third point is taken" << std::endl;
								std::cout << "mouse x: " << userVertexPromptThree.mouseButton.x << std::endl;
								std::cout << "mouse y: " << userVertexPromptThree.mouseButton.y << std::endl;

								pointThreeX = userVertexPromptThree.mouseButton.x;
								pointThreeY = userVertexPromptThree.mouseButton.y;

								vertexThreeIndicator.setPosition(pointThreeX, pointThreeY);
								vertexThreeIndicator.setFillColor(Color(255, 0, 0));

								vertexThree = true;
							}
						}
						window.clear();
						window.draw(vertexOneIndicator);
						window.draw(vertexTwoIndicator);
						window.draw(vertexThreeIndicator);
						window.draw(vertexThreeText);
						window.display();
					}
				}
				//Repeat for the user initialization point
				else if (!initialPoint)
				{
					while (window.pollEvent(initialPointPrompt))
					{
						if (initialPointPrompt.type == Event::Closed)
						{
							window.close();
						}
						if (initialPointPrompt.type == Event::MouseButtonPressed)
						{
							if (initialPointPrompt.mouseButton.button == Mouse::Left)
							{
								std::cout << "The starting point is taken" << std::endl;
								std::cout << "mouse x: " << initialPointPrompt.mouseButton.x << std::endl;
								std::cout << "mouse y: " << initialPointPrompt.mouseButton.y << std::endl;

								clicked.x = initialPointPrompt.mouseButton.x;
								clicked.y = initialPointPrompt.mouseButton.y;

								inputX = clicked.x;
								inputY = clicked.y;

								initialPointIndicator.setPosition(inputX, inputY);
								initialPointIndicator.setFillColor(Color(255, 0, 0));

								initialPoint = true;
							}
						}
						window.clear();
						window.draw(vertexOneIndicator);
						window.draw(vertexTwoIndicator);
						window.draw(vertexThreeIndicator);
						window.draw(initialPointIndicator);
						window.draw(initialPointText);
						window.display();
					}
				}
			}



		// Exit program if escape is pressed
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		//Chooses a random vertex at the start of every frame
		randomVertex = rand() % 3;


		/*
		****************************************
		Handle the Fractal Math
		****************************************
		*/
		if (randomVertex == 1)
		{
			//Temp point to hold the new coordinates
			int tempPointX = (inputX + pointOneX) / 2;
			int tempPointY = (inputY + pointOneY) / 2;

			//Pushes new coordinates into the end of the vertex
			xPos.push_back(tempPointX);
			yPos.push_back(tempPointY);

			//Sets previous point to the new point so that next frame the starting point is correct
			inputX = tempPointX;
			inputY = tempPointY;
		}
		//Same explanation above but for vertex two
		else if (randomVertex == 2)
		{
			int tempPointX = (inputX + pointTwoX) / 2;
			int tempPointY = (inputY + pointTwoY) / 2;

			xPos.push_back(tempPointX);
			yPos.push_back(tempPointY);

			inputX = tempPointX;
			inputY = tempPointY;
		}
		//Same explanation above but for vertex three
		else
		{
			int tempPointX = (inputX + pointThreeX) / 2;
			int tempPointY = (inputY + pointThreeY) / 2;

			xPos.push_back(tempPointX);
			yPos.push_back(tempPointY);

			inputX = tempPointX;
			inputY = tempPointY;
		}

		/*
		****************************************
		Display points in vector
		****************************************
		*/

		//Clear everything from the last frame
		window.clear();

		//Draw each point in the vertex (expands infinitely until program is closed through escape)
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


