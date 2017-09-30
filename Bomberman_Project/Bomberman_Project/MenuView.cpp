#include "MenuView.h"

std::string MenuView::m_keyMapForSpriteSheet = MAIN_SPRITE_SHEET;

MenuView::MenuView()
{
	addButtonInMapping(new Button(NormalButton, COORD_PLAY_BUTTON, "Jouer", COLOR_TEXT_BUTTON_MENU, SIZE_TEXT, MAIN_FONT), &ActionButton::launchGame);
	addButtonInMapping(new Button(NormalButton, COORD_OPTION_BUTTON, "Option", COLOR_TEXT_BUTTON_MENU, SIZE_TEXT, MAIN_FONT), &ActionButton::optionView);
	addButtonInMapping(new Button(NormalButton, COORD_QUIT_BUTTON, "Quitter", COLOR_TEXT_BUTTON_MENU, SIZE_TEXT, MAIN_FONT), &ActionButton::quitGame);

	m_verticesToDisplay.setPrimitiveType(sf::Quads);
}



void MenuView::updateVertexArray()
{
	for (std::map< Button*, std::function< ScreenToDisplay(ActionButton&) > >::iterator it = m_mapOfButton.begin(); it != m_mapOfButton.end(); ++it) {
		for (sf::Vertex vertex : it->first->getButtonVerticesSprite())
		{
			m_verticesToDisplay.append(vertex);
		}
	}
}



void MenuView::concatVectors(std::vector< sf::Vertex >& base_vector, std::vector< sf::Vertex >& vector_to_concat)
{
	for (sf::Vertex vertex : vector_to_concat)
	{
		base_vector.push_back(vertex);
	}
}



ScreenToDisplay MenuView::displayMenu(sf::RenderWindow* window)
{
	m_verticesToDisplay.clear();

	updateVertexArray();

	window->draw(m_verticesToDisplay, Sprite::getSpriteSheet(m_keyMapForSpriteSheet));
	
	for (std::map< Button*, std::function< ScreenToDisplay(ActionButton&) > >::iterator it = m_mapOfButton.begin(); it != m_mapOfButton.end(); ++it) {
		window->draw(*it->first->getTextButton()); // Request to draw on the screen the circle. (Limit the draw call for memory)
	}

	return updateButtonVerticesAndCheckButtonClicked(window, false);
}



ScreenToDisplay MenuView::updateButtonVerticesAndCheckButtonClicked(sf::RenderWindow* window, const bool click_event)
{
	sf::Vector2i coord_mouse = sf::Mouse::getPosition(*window);
	ScreenToDisplay tmpScreenToDisplay = Menu;

	for (std::map< Button*, std::function< ScreenToDisplay(ActionButton&) > >::iterator it = m_mapOfButton.begin(); it != m_mapOfButton.end(); ++it) {
		if (it->first->normalButtonCheckMouseHoverAndClicked(coord_mouse, click_event))
		{
			tmpScreenToDisplay = it->second(m_actionButton);
		}
	}

	return tmpScreenToDisplay;
}



MenuView::~MenuView()
{
}
