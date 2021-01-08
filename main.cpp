#include <SFML/Graphics.hpp>
#include "Tetris_Block.hpp"
#include "Field.hpp"
#include <iostream>
#include <string>

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	//sf::ContextSettings setings;
	//setings.antialiasingLevel = 8; // сглаживание

	sf::RenderWindow window(sf::VideoMode(550, 500), "Tetris", sf::Style::Default);
	//--------------------------------------------------------------------------------------

	// тектстуры и спрайты
	sf::Texture textureTetramino, backgroundField;
	textureTetramino.loadFromFile("Texture_block.png");
	backgroundField.loadFromFile("Field.png");
	sf::Sprite spriteTetramino(textureTetramino), spriteBackground(backgroundField);
	//--------------------------------------------------------------------------------------

	Block block(RandTetramino());
	Field field(block);

	sf::Font font;
	font.loadFromFile("fonts_for_score.ttf");

	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(24);
	scoreText.setStyle(sf::Text::Bold);
	scoreText.setFillColor(sf::Color::Black);
	scoreText.setPosition(435.f, 217.f);

	double timer = 0.0, delay = 0.35;
	sf::Clock clock;

	while (window.isOpen()) {
		delay = 0.35;
		double time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		scoreText.setString(std::to_string(field.GetScore()));

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
					delay = 0.05; // "ускорение" 
				}
			}
		}
		window.clear(sf::Color::White);
		window.draw(spriteBackground);
		window.draw(scoreText);

		// движения блока вниз со временем
		if (timer > delay)
		{
			field.BlockMoveDown();
			timer = 0;
		}

		// проиграл
		if (field.isGameOver()) {
			// TODO
			window.clear(sf::Color::White);
			std::cout << "Game Over!" << std::endl;
			break;
		}

		// отрисовка спрайтов по координатам
		for (size_t i = 0; i < field.GetField().size(); ++i) {
			for (size_t j = 0; j < field.GetField()[0].size(); ++j) {
				if (field.GetField()[i][j]) {
					spriteTetramino.setPosition((i+2) * 20.f, j * 20.f);
					window.draw(spriteTetramino);
				}
			}
		}


		window.display();
	}
	return 0;
}