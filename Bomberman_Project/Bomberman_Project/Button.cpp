#include "Button.h"

Button::Button(TypeButton type_button, const sf::Vector2i& coord_screen, const std::string& text, const sf::Color& color_text, const short& size_text, const std::string key_for_font) :
	m_normalButtonSprite(new Sprite(WIDTH_NORMAL_BUTTON, HEIGHT_NORMAL_BUTTON, coord_screen, COORD_SPRITE_NORMAL)), m_coordOnScreen(coord_screen),
	m_typeButton(type_button), m_stateButton(Normal), m_textButton(new Fonts(text, size_text, color_text, key_for_font, m_normalButtonSprite->getFloatRect())), m_clockToDisplayClickedButton(new sf::Clock())
{

}

Button::Button(TypeButton type_button, const sf::Vector2i & coord_screen) :
	m_normalButtonSprite(new Sprite(WIDTH_NORMAL_BUTTON, HEIGHT_NORMAL_BUTTON, coord_screen, COORD_SPRITE_NORMAL)), m_coordOnScreen(coord_screen),
	m_typeButton(type_button), m_stateButton(Normal), m_textButton(new Fonts("", 0, sf::Color(0,0,0), MAIN_FONT, m_normalButtonSprite->getFloatRect())), m_clockToDisplayClickedButton(new sf::Clock())
{
}

void Button::changeButton()
{
	sf::Vector2i coordButtonInSpriteSheet;
	int widthSprite, heightSprite;

	if (m_typeButton == NormalButton)
	{
		switch (m_stateButton)
		{
		case Normal:
			m_normalButtonSprite->changeSpriteVerticesCoord(WIDTH_NORMAL_BUTTON, HEIGHT_NORMAL_BUTTON, m_coordOnScreen, COORD_SPRITE_NORMAL);
			break;
		case MouseHover:
			m_normalButtonSprite->changeSpriteVerticesCoord(WIDTH_MOUSE_HOVER_NORMAL_BUTTON, HEIGHT_MOUSE_HOVER_NORMAL_BUTTON, 
				sf::Vector2i(m_coordOnScreen.x - 2, m_coordOnScreen.y - 2), COORD_MOUSE_HOVER_SPRITE_NORMAL);
			break;
		case Clicked:
			m_normalButtonSprite->changeSpriteVerticesCoord(WIDTH_CLICKED_NORMAL_BUTTON, HEIGHT_CLICKED_NORMAL_BUTTON, m_coordOnScreen, COORD_CLICKED_SPRITE_NORMAL);
			break;
		case Unclickable:
			m_normalButtonSprite->changeSpriteVerticesCoord(WIDTH_UNCLICKABLE_NORMAL_BUTTON, HEIGHT_UNCLICKABLE_NORMAL_BUTTON, m_coordOnScreen, COORD_UNCLICKABLE_SPRITE_NORMAL);
			break;
		}
	}
	else if (m_typeButton == ReturnButton)
	{
		switch (m_stateButton)
		{
		case Normal:
			m_normalButtonSprite->changeSpriteVerticesCoord(WIDTH_RETURN_BUTTON, HEIGHT_RETURN_BUTTON, m_coordOnScreen, COORD_SPRITE_RETURN);
			break;
			case MouseHover:
			m_normalButtonSprite->changeSpriteVerticesCoord(WIDTH_MOUSE_HOVER_RETURN_BUTTON, HEIGHT_MOUSE_HOVER_RETURN_BUTTON, 
				sf::Vector2i(m_coordOnScreen.x - 2, m_coordOnScreen.y - 2), COORD_MOUSE_HOVER_SPRITE_RETURN);
			break;
			case Clicked:
			m_normalButtonSprite->changeSpriteVerticesCoord(WIDTH_CLICKED_RETURN_BUTTON, HEIGHT_CLICKED_RETURN_BUTTON, m_coordOnScreen, COORD_CLICKED_SPRITE_RETURN);
			break;
		}
	}
}


bool Button::normalButtonCheckMouseHoverAndClicked(const sf::Vector2i& coord_mouse, const bool click_event)
{
	if (m_normalButtonSprite->mouseHover(coord_mouse) || m_stateButton == Clicked)
	{
		if (click_event || (m_clockToDisplayClickedButton->getElapsedTime().asSeconds() <= DISPLAY_CLICKED_DELAY && m_stateButton == Clicked))
		{
			m_stateButton = Clicked;
		}
		else
		{
			if (m_stateButton == Clicked)
			{
				return true;
			}

			m_clockToDisplayClickedButton->restart();
			m_stateButton = MouseHover;

		}
	}
	else
	{
		m_clockToDisplayClickedButton->restart();
		m_stateButton = Normal;
	}

	return false;
}


std::vector< sf::Vertex > Button::getButtonVerticesSprite()
{
	changeButton();
	return m_normalButtonSprite->getSpriteVertex();
}



sf::Text * Button::getTextButton()
{
	return m_textButton->getText();
}



Button::~Button()
{
	if (m_normalButtonSprite != nullptr)
	{
		delete m_normalButtonSprite;
	}

	if (m_textButton != nullptr)
	{
		delete m_textButton;
	}

	if (m_clockToDisplayClickedButton != nullptr)
	{
		delete m_clockToDisplayClickedButton;
	}
}
