#pragma once

#include <SFML/Graphics.hpp>

const char MAIN_FONT[] = "Bomberman";
const char MAIN_FONT_PATH[] = "Fonts/Bomberman.ttf";

const char HUD_FONT[] = "Damaged";
const char HUD_FONT_PATH[] = "Fonts/Damaged.ttf";

class Fonts
{
private:
	static std::map< std::string, sf::Font* > m_fonts;

	sf::Text* m_text;

public:
	Fonts(const std::string& text, const short& size_text, const sf::Color& color_text, const std::string& key_map, const sf::FloatRect& rect_for_positioning);

	void loadFontsByFile(const std::string& new_key_map, const std::string& path);

	sf::Text* getText() const;

	~Fonts();
};

