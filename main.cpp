#include <SFML/Graphics.hpp>
#include "resourceHolder.h"

const unsigned int WINDOW_WIDTH = 840;
const unsigned int WINDOW_HEIGHT = 520;

int main() {
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Project", sf::Style::Close);
	
	ResourcecHolder<sf::Texture, Textures::ID> textures;
	textures.load(Textures::Asteroid, (std::string)"Resources/asteroid.png");
	textures.load(Textures::Spaceship, (std::string)"Resources/spaceship.png");
	
#pragma region Game Objects
	sf::Sprite player;
	player.setTexture(textures.get(Textures::Spaceship));

	sf::Sprite asteroid;
	asteroid.setTexture(textures.get(Textures::Asteroid));
#pragma endregion

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();

		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

#pragma region Updates

#pragma endregion

#pragma region Visuals
		window.clear();

		window.draw(asteroid);
		window.draw(player);
		window.display();
#pragma endregion
	}

	return 0;
}
