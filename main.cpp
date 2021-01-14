#include <SFML/Graphics.hpp>
#include "WindowGame.hpp"

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	sf::Texture textureBlock, textureBackground;
	textureBlock.loadFromFile("Texture_block.png");
	textureBackground.loadFromFile("Field.png");

	sf::Font font;
	font.loadFromFile("fonts_for_score.ttf");

	WindowGame window(550, 500, "TETRIS");
	window.setTextureBlock(textureBlock);
	window.setBackground(textureBackground);
	window.setSpeed(0.4);
	window.setParametersScoreText(font, 24, 435.0, 217.0);

	window.StartGame();

	return 0;
}