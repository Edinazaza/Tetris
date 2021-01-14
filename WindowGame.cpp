#include "WindowGame.hpp"

WindowGame::WindowGame(unsigned int hight, unsigned int width, std::string title)
	: window(sf::VideoMode(hight, width), title, sf::Style::Default)
{	
}

void WindowGame::setTextureBlock(sf::Texture& textureForBlock)
{
	spriteTetramino.setTexture(textureForBlock);
}

void WindowGame::setBackground(sf::Texture& textureForBakground)
{
	spriteBackground.setTexture(textureForBakground);
}

void WindowGame::setParametersScoreText(sf::Font& font, unsigned int size, double setPosX, double setPosY)
{
	score.setFont(font);
	score.setCharacterSize(size);
	score.setStyle(sf::Text::Bold);
	score.setFillColor(sf::Color::Black);
	score.setPosition(setPosX, setPosY);
}

void WindowGame::setSpeed(const double delay)
{
	this->delay = delay;
}

void WindowGame::StartGame()
{
	double timer = 0.0;
	sf::Clock clock;
	double speed = delay;
	while (window.isOpen()) {
		speed = delay;
		double time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		score.setString(std::to_string(field.GetScore()));

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
					speed = 0.05; // "ускорение" 
				}
			}
		}
		window.clear(sf::Color::White);
		window.draw(spriteBackground);
		window.draw(score);

		// движения блока вниз со временем
		if (timer > speed)
		{
			field.BlockMoveDown();
			timer = 0;
		}

		// проиграл
		if (field.isGameOver()) {
			// TODO
			window.clear(sf::Color::White);
			break;
		}

		// отрисовка спрайтов по координатам
		for (size_t i = 0; i < field.GetField().size(); ++i) {
			for (size_t j = 0; j < field.GetField()[0].size(); ++j) {
				if (field.GetField()[i][j]) {
					spriteTetramino.setPosition((i + 2) * 20.f, j * 20.f);
					window.draw(spriteTetramino);
				}
			}
		}
		window.display();
	}
}
