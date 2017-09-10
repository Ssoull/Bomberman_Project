#pragma once

#include <SFML/Graphics.hpp> // Allows the use of SFML.

#include <iostream> // Allows the use of input and output in the console. 

/***********************************************\
*  This class represents the part of MVC model  *
* which display the game on the screen.         *
\***********************************************/
class View
{
private:
	sf::RenderWindow* m_window; // Represent the window.

	short m_widthWindow; // Represents the width of the window.
	short m_heightWindow; // Represents the height of the window.

public:
	View(const short width_window, const short height_window); // Constructor.

	void displayGame(); // Display the game.

	bool windowClosed(); // Check if the window is closed.

	~View(); // Destructor.
};