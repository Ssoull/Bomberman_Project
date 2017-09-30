#pragma once

#include <SFML/Graphics.hpp> // Allows the use of SFML.
#include <vector> // Allows the use of vector.
#include <map> // Allows the use of map.
#include <string> // Allows the use of string.

const char MAIN_SPRITE_SHEET[] = "main_sprite_sheet";
const char MAIN_SPRITE_SHEET_PATH[] = "Sprites/spriteSheet.bmp";

/***********************************************\
*  This class contains element linked by        * 
* graphics (sprite sheet, sprite).              *
\***********************************************/
class Sprite
{
private:
	//static std::map< std::string, sf::Texture* >& getMap(); // Represent the method that contains all of the sprite sheet (static = same value for every object GraphicElements).
	static std::map< std::string, sf::Texture* > m_spriteSheet;

	std::vector< sf::Vertex > m_sprite;

	int m_widthSprite; // Represent the width of the sprite.
	int m_heightSprite; // Represent the height of the sprite.

	sf::Vector2i m_coordSpriteOnScreen; // Represent the coordinates on the screen of the sprite.
	sf::Vector2i m_coordSpriteInSpriteSheet; // Represent the coordinates in the sprite sheet of the sprite that we want (origin: upper left).

	

public:
	Sprite(const short& width_sprite, const short& height_sprite, const sf::Vector2i& coord_on_screen, const sf::Vector2i& coord_in_sprite_sheet); // Constructor.

	void loadSpriteSheetByFile(const std::string& new_key_map, const std::string& path_file); // Load sprite sheet in memory thanks to a path file.

	void changeSpriteVerticesCoord(const short& width_sprite, const short& height_sprite, const sf::Vector2i& coord_on_screen, const sf::Vector2i& coord_in_sprite_sheet);

	bool mouseHover(const sf::Vector2i& coord_mouse) const;

	std::vector< sf::Vertex > getSpriteVertex() const;
	static sf::Texture* getSpriteSheet(const std::string& key_map);
	sf::FloatRect getFloatRect() const;

	~Sprite(); // Destructor.
};