#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "Field.hpp"

class WindowGame
{
public:
	WindowGame(unsigned int hight, unsigned int width, std::string title);

	void setTextureBlock(sf::Texture& textureForBlock);
	void setBackground(sf::Texture& textureForBakground);
	void setParametersScoreText(sf::Font& font, unsigned int size, double setPosX, double setPosY);


	void setSpeed(const double delay);
	void StartGame();

private:
	sf::RenderWindow window;
	sf::Sprite spriteTetramino;
	sf::Sprite spriteBackground;
	sf::Text score; 
	Field field{ RandTetramino() };
	double delay = 0.35;
};