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

	while (window.isOpen()) {
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
			window.close();
		}

		window.clear();

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