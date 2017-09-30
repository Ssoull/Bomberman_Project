#include "Fonts.h"
#include <iostream>

std::map< std::string, sf::Font* > Fonts::m_fonts;

Fonts::Fonts(const std::string& text, const short& size_text, const sf::Color& color_text, const std::string& key_map, const sf::FloatRect& rect_for_positioning)
{
	if (m_fonts.empty())
	{
		loadFontsByFile(MAIN_FONT, MAIN_FONT_PATH);
		loadFontsByFile(HUD_FONT, HUD_FONT_PATH);
	}
	
	m_text = new sf::Text(text, *m_fonts[key_map], size_text);
	m_text->setColor(color_text);

	short coordX = rect_for_positioning.left + (rect_for_positioning.width / 2) - (m_text->getLocalBounds().width / 2);
	short coordY = rect_for_positioning.top + (rect_for_positioning.height / 2) - (m_text->getLocalBounds().height / 2 + 5);
	m_text->setPosition(coordX, coordY);
 }



void Fonts::loadFontsByFile(const std::string& new_key_map, const std::string& path)
{
	sf::Font* tmpFont = new sf::Font();

	if (tmpFont->loadFromFile(path))
	{
		m_fonts[new_key_map] = tmpFont;
	}
}

sf::Text* Fonts::getText() const
{
	return m_text;
}



Fonts::~Fonts()
{
	if (m_text != nullptr)
	{
		delete m_text;
	}

	if (m_fonts[MAIN_FONT] != nullptr) // If the texture object pointer is correctly initialized.
	{
		sf::Font* tmpFont = m_fonts[MAIN_FONT];
		m_fonts.erase(MAIN_FONT);
		delete tmpFont; // Desallocates a block of memory.
	}

	if (m_fonts[HUD_FONT] != nullptr) // If the texture object pointer is correctly initialized.
	{
		sf::Font* tmpFont = m_fonts[HUD_FONT];
		m_fonts.erase(HUD_FONT);
		delete tmpFont; // Desallocates a block of memory.
	}
}
