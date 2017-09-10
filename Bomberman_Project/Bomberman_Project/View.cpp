#include "View.h"

/***********************************\
*  Constructor of the class view.   *
\***********************************/
View::View(const short width_window, const short height_window) : m_widthWindow(width_window), m_heightWindow(height_window)
{
	m_window = new sf::RenderWindow(sf::VideoMode(m_widthWindow, m_heightWindow), "SFML works!"); // Initialyze the window in the memory.
	m_window->setFramerateLimit(60); // Limit the framerate to 60 fps (Important to limit the use of the CPU).
}



/***********************************\
*  Display the game.                *
\***********************************/
void View::displayGame()
{
	sf::CircleShape circle_one(100.f); // Create a circle.
	sf::CircleShape circle_two(100.f); // Create a circle.
	sf::CircleShape circle_three(100.f); // Create a circle.
	sf::CircleShape circle_four(100.f); // Create a circle.

	circle_two.setPosition(0, 200.f); // Set the position.
	circle_three.setPosition(200.f, 200.f); // Set the position.
	circle_four.setPosition(200.f, 0); // Set the position.

	circle_one.setFillColor(sf::Color::Green); // Change the color of the circle to green.
	circle_two.setFillColor(sf::Color::Red); // Change the color of the circle to red.
	circle_three.setFillColor(sf::Color::Yellow); // Change the color of the circle to yellow.
	circle_four.setFillColor(sf::Color::Blue); // Change the color of the circle to blue.

	m_window->clear(); // Clear the window (Important for memory).

	m_window->draw(circle_one); // Request to draw on the screen the circle. (Limit the draw call for memory)
	m_window->draw(circle_two); // Request to draw on the screen the circle. (Limit the draw call for memory)
	m_window->draw(circle_three); // Request to draw on the screen the circle. (Limit the draw call for memory)
	m_window->draw(circle_four); // Request to draw on the screen the circle. (Limit the draw call for memory)

	m_window->display(); // Answer every request of draw.
}



/***********************************\
*  Check if the player close        *
* the window.                       *
\***********************************/
bool View::windowClosed()
{
	sf::Event event; // Declare the variable.
	while (m_window->pollEvent(event)) // While there is events on the window.
	{
		if (event.type == sf::Event::Closed) // If the event is "Closed".
		{
			m_window->close(); // Closed the window.
			return true;
		}
	}

	return false;
}



/***********************************\
*  Destructor of the view.          *
\***********************************/
View::~View()
{
	std::cout << "Here i'm in the view destructor." << std::endl;

	if (m_window != nullptr) // If m_window is initialized.
	{
		delete m_window; // Deallocates a block of memory.
	}
}
