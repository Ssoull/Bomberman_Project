#include "View.h"


/***********************************\
*  Constructor of the class view.   *
\***********************************/
View::View(Model* model, const short width_window, const short height_window) : m_model(model), m_widthWindow(width_window), m_heightWindow(height_window), m_menuView(new MenuView()), m_screenToDisplay(Menu)
{
	m_window = new sf::RenderWindow(sf::VideoMode(m_widthWindow, m_heightWindow), "BomberMan"); // Initialyze the window in the memory.
	m_window->setFramerateLimit(60); // Limit the framerate to 60 fps (Important to limit the use of the CPU).
}



/***********************************\
*  Display the game.                *
\***********************************/
void View::displayGame()
{
	m_window->clear(); // Clear the window (Important for memory).

	screenToDisplay();

	m_window->display(); // Answer every request of draw.
}



void View::screenToDisplay()
{
	if (m_screenToDisplay == Menu)
	{
		m_screenToDisplay = m_menuView->displayMenu(m_window);
	}
	else if (m_screenToDisplay == Option)
	{

	}
	else if (m_screenToDisplay == Quit)
	{
		m_model->quitTheGame();
	}
}

bool View::checkMouseClickInWindow()
{
	sf::Vector2i coord_mouse = sf::Mouse::getPosition(*m_window);
	if (0 <= coord_mouse.x && m_widthWindow >= coord_mouse.x &&
		0 <= coord_mouse.y && m_heightWindow >= coord_mouse.y)
	{
		return true;
	}

	return false;
}

void View::checkButtonStateOnMouseClick()
{
	switch (m_screenToDisplay)
	{
	case Menu:
		m_menuView->updateButtonVerticesAndCheckButtonClicked(m_window, true);
		break;
	}
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
	if (m_window != nullptr) // If m_window is initialized.
	{
		delete m_window; // Deallocates a block of memory.
	}

	if (m_menuView != nullptr)
	{
		delete m_menuView;
	}
}
