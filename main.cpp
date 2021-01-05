#include <SFML/Graphics.hpp>
#include "Tetris_Block.hpp"
#include "Field.hpp"

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
	Field field(block);

	double timer = 0.0, delay = 0.35;
	sf::Clock clock;

	while (window.isOpen()) {
		delay = 0.35;
		double time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Left) {
					field.BlockMoveLeft();
				}
				else if (event.key.code == sf::Keyboard::Right) {
					field.BlockMoveRight();
				}
				else if (event.key.code == sf::Keyboard::Up) {
					field.BlockRotate();
				}
				else if (event.key.code == sf::Keyboard::Down) {
					delay = 0.05;
				}
			}
		}
		window.clear(sf::Color::White);
		
		if (timer > delay)
		{
			field.BlockMoveDown();
			timer = 0;
		}

		for (size_t i = 0; i < field.GetField().size(); ++i) {
			for (size_t j = 0; j < field.GetField()[i].size(); ++j) {
				if (field.GetField()[i][j]) {
					spriteTetramino.setPosition(i * 20.f, j * 20.f);
					window.draw(spriteTetramino);
				}
			}
		}

		window.display();
	}
	return 0;
}