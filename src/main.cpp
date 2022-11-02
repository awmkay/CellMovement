#include "Player.hpp"

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>

void handleEvents(sf::RenderWindow &window);
void handleInput();

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int GRID_WIDTH = 64;
const int GRID_HEIGHT = 48;

Player player;

int main() {
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML");
	sf::Clock clock;
	sf::Time deltaTime = sf::Time::Zero;

	while (window.isOpen()) {
		deltaTime = clock.restart();
		handleEvents(window);
		player.update(deltaTime);

		window.clear(sf::Color::Black);
		player.draw(window);
		window.display();
	}
}

void handleEvents(sf::RenderWindow &window) {
	sf::Event event;
	while (window.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				return;
			default:
				break;
		}
	}
	handleInput();
}

void handleInput() {
	int dx = 0, dy = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		dy--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		dx--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		dy++;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		dx++;

	player.process(dx, dy);
}
