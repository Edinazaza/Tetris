#include <SFML/Graphics.hpp>


int main()
{
	sf::ContextSettings setings;
	setings.antialiasingLevel = 8; // сглаживание
	sf::RenderWindow window(sf::VideoMode(600, 600), "Tetris", sf::Style::Default, setings);
	
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {

			}
		}
		window.clear(sf::Color::White);
				
		window.display();
		sf::sleep(sf::milliseconds(170));
	}
	return 0;
}