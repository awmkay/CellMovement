#ifndef CELLMOVEMENT_PLAYER_H
#define CELLMOVEMENT_PLAYER_H

#include <SFML/Graphics.hpp>

const extern int GRID_WIDTH;
const extern int GRID_HEIGHT;

enum MovementType {
	SMOOTH,
	CELL_BASED
};

class Player {
	public:
		Player();
		void draw(sf::RenderWindow& window);
		void update(sf::Time deltaTime);
		void process(int dx, int dy);

	private:
		void checkCollision();

	private:
		const int SIZE = 10;
		const int VELOCITY = 10;
		const MovementType movementType = CELL_BASED;

		float x;
		float y;
		int dx;
		int dy;
		sf::RectangleShape sprite;
};

#endif
