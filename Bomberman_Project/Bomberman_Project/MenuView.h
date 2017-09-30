#pragma once

#include "Button.h"
#include "MappingButton.h"

const sf::Vector2i COORD_PLAY_BUTTON(409, 250);
const sf::Vector2i COORD_OPTION_BUTTON(409, 350);
const sf::Vector2i COORD_QUIT_BUTTON(409, 450);

const sf::Color COLOR_TEXT_BUTTON_MENU(50, 50, 50);

const short SIZE_TEXT = 24;

class MenuView : public MappingButton
{
private:
	static std::string m_keyMapForSpriteSheet;

	sf::VertexArray m_verticesToDisplay;

public:
	MenuView();

	void updateVertexArray();
	void concatVectors(std::vector< sf::Vertex >& base_vector, std::vector< sf::Vertex >& vector_to_concat);
	ScreenToDisplay displayMenu(sf::RenderWindow* window);
	ScreenToDisplay updateButtonVerticesAndCheckButtonClicked(sf::RenderWindow* window, const bool click_event);

	~MenuView();
};

