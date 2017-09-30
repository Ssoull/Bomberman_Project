#pragma once

#include "Sprite.h"
#include "Fonts.h"

const short WIDTH_NORMAL_BUTTON = 181;
const short HEIGHT_NORMAL_BUTTON = 55;
const sf::Vector2i COORD_SPRITE_NORMAL(1, 1);

const short WIDTH_MOUSE_HOVER_NORMAL_BUTTON = 185;
const short HEIGHT_MOUSE_HOVER_NORMAL_BUTTON = 59;
const sf::Vector2i COORD_MOUSE_HOVER_SPRITE_NORMAL(1, 169);

const short WIDTH_CLICKED_NORMAL_BUTTON = 181;
const short HEIGHT_CLICKED_NORMAL_BUTTON = 55;
const sf::Vector2i COORD_CLICKED_SPRITE_NORMAL(1, 57);

const short WIDTH_UNCLICKABLE_NORMAL_BUTTON = 181;
const short HEIGHT_UNCLICKABLE_NORMAL_BUTTON = 55;
const sf::Vector2i COORD_UNCLICKABLE_SPRITE_NORMAL(1, 113);

const short WIDTH_RETURN_BUTTON = 38;
const short HEIGHT_RETURN_BUTTON = 26;
const sf::Vector2i COORD_SPRITE_RETURN(226, 1);

const short WIDTH_MOUSE_HOVER_RETURN_BUTTON = 42;
const short HEIGHT_MOUSE_HOVER_RETURN_BUTTON = 30;
const sf::Vector2i COORD_MOUSE_HOVER_SPRITE_RETURN(183, 1);

const short WIDTH_CLICKED_RETURN_BUTTON = 38;
const short HEIGHT_CLICKED_RETURN_BUTTON = 26;
const sf::Vector2i COORD_CLICKED_SPRITE_RETURN(265, 1);

enum TypeButton { NormalButton, ReturnButton };
enum StateButton { Normal, MouseHover, Clicked, Unclickable };

const double DISPLAY_CLICKED_DELAY = 0.6; // TODO: Determine the time according to the duration of the click sound

/***********************************************\
*  This class represents the part of MVC pattern*
* which display the game on the screen.         *
\***********************************************/
class Button
{
private:

	Sprite* m_normalButtonSprite;

	sf::Vector2i m_coordOnScreen;

	/*Sprite* m_normalButtonSprite;
	Sprite* m_mouseHoverButtonSprite;
	Sprite* m_clickedButtonSprite;
	Sprite* m_unclickableButtonSprite;*/

	TypeButton m_typeButton;
	StateButton m_stateButton;

	Fonts* m_textButton;

	sf::Clock* m_clockToDisplayClickedButton;

public:
	Button(TypeButton type_button, const sf::Vector2i& coord_screen, const std::string& text, const sf::Color& color_text, const short& size_text, const std::string key_for_font); // Constructor.
	Button(TypeButton type_button, const sf::Vector2i& coord_screen); // Constructor.

	void changeButton();
	bool normalButtonCheckMouseHoverAndClicked(const sf::Vector2i& coord_mouse, const bool click_event);

	std::vector< sf::Vertex > getButtonVerticesSprite();
	sf::Text* getTextButton();

	~Button(); // Destructor.
};