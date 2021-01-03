#include <SFML/Graphics.hpp>
#include "Tetris_Block.hpp"

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	sf::ContextSettings setings;
	setings.antialiasingLevel = 8; // сглаживание
	sf::RenderWindow window(sf::VideoMode(600, 600), "Tetris", sf::Style::Default, setings);
	//--------------------------------------------------------------------------------------

	sf::Texture textureTetramino;
	textureTetramino.loadFromFile("Texture_block.png");
	sf::Sprite spriteTetramino(textureTetramino);
	//--------------------------------------------------------------------------------------


	Block block(RandTetramino());


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Left) {
					block.MoveLeft();
				}
				else if (event.key.code == sf::Keyboard::Right) {
					block.MoveRight();
				}
				else if (event.key.code == sf::Keyboard::Up) {
					block.Rotate();
				}
				else if (event.key.code == sf::Keyboard::Down) {
					block.MoveDown();
				}
			}
		}
		window.clear(sf::Color::White);
				
		for (const auto coord : block.GetCoordinate())
		{
			spriteTetramino.setPosition(coord.first * 20.f, coord.second * 20.f);
			window.draw(spriteTetramino);
		}

		window.display();
		sf::sleep(sf::milliseconds(170));
	}
	return 0;
}