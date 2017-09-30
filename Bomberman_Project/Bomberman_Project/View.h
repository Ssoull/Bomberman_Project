#pragma once

#include "Model.h"
#include "MenuView.h"

#include <SFML/Graphics.hpp> // Allows the use of SFML.
#include <iostream> // Allows the use of input and output in the console.

const short WIDTH_WINDOW = 1000;
const short HEIGHT_WINDOW = 600;

/***********************************************\
*  This class represents the part of MVC pattern*
* which display the game on the screen.         *
\***********************************************/
class View
{
private:

	Model* m_model;

	sf::RenderWindow* m_window; // Represent the window.

	short m_widthWindow; // Represents the width of the window.
	short m_heightWindow; // Represents the height of the window.

	MenuView* m_menuView;

	ScreenToDisplay m_screenToDisplay;

public:
	View(Model* model, const short width_window, const short height_window); // Constructor.

	void displayGame(); // Display the game.
	void screenToDisplay();

	bool checkMouseClickInWindow();
	void checkButtonStateOnMouseClick();

	bool windowClosed(); // Check if the window is closed.

	~View(); // Destructor.
};