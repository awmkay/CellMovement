#include "Player.hpp"

#include <cmath>
#include <algorithm>
#include <iostream>

Player::Player() : sprite({(float)SIZE, (float)SIZE}) {
	sprite.setPosition(0, 0);
	sprite.setFillColor(sf::Color::Red);
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

void Player::update(sf::Time deltaTime) {
	x += dx * deltaTime.asSeconds() * VELOCITY;
	y += dy * deltaTime.asSeconds() * VELOCITY;

	checkCollision();

	switch (movementType) {
		case SMOOTH:
			sprite.setPosition(x * SIZE, y * SIZE);
		case CELL_BASED:
			sprite.setPosition(std::floor(x) * SIZE, std::floor(y) * SIZE);
	}
}

void Player::process(int dx, int dy) {
	this->dx = dx;
	this->dy = dy;
}

void Player::checkCollision() {
	if (x < 0)
		x = 0;
	else if (x > GRID_WIDTH - 1)
		x = GRID_WIDTH - 1;

	if (y < 0)
		y = 0;
	else if (y > GRID_HEIGHT - 1)
		y = GRID_HEIGHT - 1;
}
