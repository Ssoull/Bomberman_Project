#include "Sprite.h"

/*std::map< std::string, sf::Texture* >& Sprite::getMap() {
	static std::map< std::string, sf::Texture* > TheObject;
	return TheObject;
}*/

std::map< std::string, sf::Texture* > Sprite::m_spriteSheet;

/*******************************************\
*  Constructor of the class Sprite.         *
\*******************************************/
Sprite::Sprite(const short& width_sprite, const short& height_sprite, const sf::Vector2i& coord_on_screen, const sf::Vector2i& coord_in_sprite_sheet)
{
	if (m_spriteSheet.empty()) // If sprite sheets are not yet loaded in memory.
	{
		loadSpriteSheetByFile(MAIN_SPRITE_SHEET, MAIN_SPRITE_SHEET_PATH); // Sprite sheet to load.
	}

	changeSpriteVerticesCoord(width_sprite, height_sprite, coord_on_screen, coord_in_sprite_sheet);
}


/*******************************************\
*  Used to load texture from a path file.   *
\*******************************************/
void Sprite::loadSpriteSheetByFile(const std::string& new_key_map, const std::string& path_file)
{
	sf::Image tmpToLoadSpriteSheetAndApplyMask;

	if (tmpToLoadSpriteSheetAndApplyMask.loadFromFile(path_file))
	{
		tmpToLoadSpriteSheetAndApplyMask.createMaskFromColor(sf::Color(0, 255, 255));
		sf::Texture* tmpToLoadSpriteSheet = new sf::Texture(); // Temporary texture object pointer.

		if (tmpToLoadSpriteSheet->loadFromImage(tmpToLoadSpriteSheetAndApplyMask)) // If the sprite sheet is correctly load.
		{
			tmpToLoadSpriteSheet->setSmooth(true);
			m_spriteSheet[new_key_map] = tmpToLoadSpriteSheet; // The texture object pointer is add to the vector with all textures object pointer.
		}
	}
}

void Sprite::changeSpriteVerticesCoord(const short& width_sprite, const short& height_sprite, const sf::Vector2i& coord_on_screen, const sf::Vector2i& coord_in_sprite_sheet)
{
	m_coordSpriteInSpriteSheet = coord_in_sprite_sheet;
	m_widthSprite = width_sprite;
	m_heightSprite = height_sprite;
	m_coordSpriteOnScreen = coord_on_screen;

	m_sprite.clear();

	m_sprite.push_back(sf::Vertex((sf::Vector2f)m_coordSpriteOnScreen, (sf::Vector2f)m_coordSpriteInSpriteSheet));
	m_sprite.push_back(sf::Vertex(sf::Vector2f((float)(m_coordSpriteOnScreen.x + m_widthSprite), (float)m_coordSpriteOnScreen.y), sf::Vector2f((float)(m_coordSpriteInSpriteSheet.x + m_widthSprite), (float)m_coordSpriteInSpriteSheet.y)));
	m_sprite.push_back(sf::Vertex(sf::Vector2f((float)(m_coordSpriteOnScreen.x + m_widthSprite), (float)(m_coordSpriteOnScreen.y + m_heightSprite)), sf::Vector2f((float)(m_coordSpriteInSpriteSheet.x + m_widthSprite), (float)(m_coordSpriteInSpriteSheet.y + m_heightSprite))));
	m_sprite.push_back(sf::Vertex(sf::Vector2f((float)m_coordSpriteOnScreen.x, (float)(m_coordSpriteOnScreen.y + m_heightSprite)), sf::Vector2f((float)m_coordSpriteInSpriteSheet.x, (float)(m_coordSpriteInSpriteSheet.y + m_heightSprite))));

}



bool Sprite::mouseHover(const sf::Vector2i& coord_mouse) const
{
	if (m_coordSpriteOnScreen.x <= coord_mouse.x && m_coordSpriteOnScreen.x + m_widthSprite >= coord_mouse.x &&
		m_coordSpriteOnScreen.y <= coord_mouse.y && m_coordSpriteOnScreen.y + m_heightSprite >= coord_mouse.y) 
	{
		return true;
	}

	return false;
}



std::vector< sf::Vertex > Sprite::getSpriteVertex() const
{
	return m_sprite;
}

sf::Texture* Sprite::getSpriteSheet(const std::string& key_map)
{
	return m_spriteSheet[key_map];
}

sf::FloatRect Sprite::getFloatRect() const
{
	return sf::FloatRect((float)m_coordSpriteOnScreen.x, (float)m_coordSpriteOnScreen.y, (float)m_widthSprite, (float)m_heightSprite);
}



Sprite::~Sprite()
{
	if (m_spriteSheet[MAIN_SPRITE_SHEET] != nullptr) // If the texture object pointer is correctly initialized.
	{
		sf::Texture* tmpTexture = m_spriteSheet[MAIN_SPRITE_SHEET];
		m_spriteSheet.erase(MAIN_SPRITE_SHEET);
		delete tmpTexture; // Desallocates a block of memory.
	}
}
