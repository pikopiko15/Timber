#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
	
	RenderWindow window(VideoMode({1920, 1080}), "Timber!", Style::Default);

	Texture textureBackground;
	Texture textureTree;
	Texture textureBee;
	Texture textureCloud;

	textureBackground.loadFromFile("graphics/background.png");
	textureTree.loadFromFile("graphics/tree.png");
	textureBee.loadFromFile("graphics/bee.png");
	textureCloud.loadFromFile("graphics/cloud.png");

	Sprite spriteBackground(textureBackground);
	Sprite spriteTree(textureTree);
	Sprite spriteBee(textureBee);
	Sprite spriteCloud1(textureCloud);
	Sprite spriteCloud2(textureCloud);
	Sprite spriteCloud3(textureCloud);

	spriteBackground.setPosition({0.0f, 0.0f});
	spriteTree.setPosition({810.0f, 0.0f});
	spriteBee.setPosition({0.0f, 800.0f});
	spriteCloud1.setPosition({0.0f, 0.0f});
	spriteCloud2.setPosition({0.0f, 250.0f});
	spriteCloud3.setPosition({0.0f, 500.0f});

	bool isBeeActive = false;
	bool isCloud1Active = false;
	bool isCloud2Active = false;
	bool isCloud3Active = false;

	float beeSpeed = 0.0f;
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;

	Clock clock;

	while (window.isOpen()) {
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
			window.close();
		}

		window.clear();

		Time dt = clock.restart();

		if (!isBeeActive) {
			srand((int)time(0));
			beeSpeed = (rand() % 200) + 200;

			srand((int)time(0) * 10);
			float height = (rand() % 500) + 500;
			spriteBee.setPosition({2000, height});
			isBeeActive = true;
		}
		else {
			spriteBee.setPosition({spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y});

			if (spriteBee.getPosition().x < -100) {
				isBeeActive = false;
			}
		}

		if (!isCloud1Active) {
			srand((int)time(0) * 10);
			cloud1Speed = (rand() % 200);

			srand((int)time(0) * 10);
			float height = (rand() % 150);
			spriteCloud1.setPosition({-200, height});
			isCloud1Active = true;
		}
		else {
			spriteCloud1.setPosition({spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()), spriteCloud1.getPosition().y});

			if (spriteCloud1.getPosition().x > 1920) {
				isCloud1Active = false;
			}
		}

		if (!isCloud2Active) {
			srand((int)time(0) * 20);
			cloud2Speed = (rand() % 200);

			srand((int)time(0) * 20);
			float height = (rand() % 300) - 150;
			spriteCloud2.setPosition({ -200, height });
			isCloud2Active = true;
		}
		else {
			spriteCloud2.setPosition({ spriteCloud2.getPosition().x + (cloud2Speed * dt.asSeconds()), spriteCloud2.getPosition().y });

			if (spriteCloud2.getPosition().x > 1920) {
				isCloud2Active = false;
			}
		}

		if (!isCloud3Active) {
			srand((int)time(0) * 30);
			cloud3Speed = (rand() % 200);

			srand((int)time(0) * 30);
			float height = (rand() % 450) - 150;
			spriteCloud3.setPosition({ -200, height });
			isCloud3Active = true;
		}
		else {
			spriteCloud3.setPosition({ spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()), spriteCloud3.getPosition().y });

			if (spriteCloud3.getPosition().x > 1920) {
				isCloud3Active = false;
			}
		}

		window.draw(spriteBackground);

		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);

		window.draw(spriteTree);
		window.draw(spriteBee);
		
		window.display();
	}

	return 0;
}