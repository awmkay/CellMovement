#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>

void handleEvents(sf::RenderWindow &window);
void handleInput();
void update(sf::Time deltaTime);

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int GRID_WIDTH = 32;
const int GRID_HEIGHT = 24;
const int PLAYER_SIZE = 20;
const int PLAYER_VELOCITY = 5;

struct {
	float x;
	float y;
	int cellx;
	int celly;
	int dx;
	int dy;
	sf::RectangleShape sprite;
} player;

int main() {
	player.x = 0;
	player.y = 0;
	player.cellx = 0;
	player.celly = 0;
	player.dx = 0;
	player.dy = 0;

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML");
	sf::Clock clock;
	sf::Time deltaTime = sf::Time::Zero;

	player.sprite.setFillColor(sf::Color::Red);
	player.sprite.setSize({PLAYER_SIZE, PLAYER_SIZE});

	while (window.isOpen()) {
		deltaTime = clock.restart();
		handleEvents(window);
		handleInput();

		update(deltaTime);

		window.clear(sf::Color::Black);
		window.draw(player.sprite);
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
			default:
				break;
		}
	}
}

void handleInput() {
	player.dx = 0;
	player.dy = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		player.dy--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		player.dx--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		player.dy++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		player.dx++;
	}
}

void update(sf::Time deltaTime) {
	// Set player position
	std::cout << deltaTime.asSeconds() << " " << player.x << " " << player.y << std::endl;
	player.x += player.dx * deltaTime.asSeconds() * PLAYER_VELOCITY;
	player.y += player.dy * deltaTime.asSeconds() * PLAYER_VELOCITY;
	player.cellx = std::clamp((int)player.x, 0, SCREEN_WIDTH / PLAYER_SIZE - 1);
	player.celly = std::clamp((int)player.y, 0, SCREEN_HEIGHT / PLAYER_SIZE - 1);

	// Set sprite position
	player.sprite.setPosition(player.cellx* PLAYER_SIZE, player.celly * PLAYER_SIZE);
}
