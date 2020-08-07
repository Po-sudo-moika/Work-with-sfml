#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <locale.h>


using namespace sf;
using namespace std;

int main();
int trainingKeyboard();

void trainingKeyboardMenu() {
	RenderWindow window4(sf::VideoMode(1376, 726), "KeyMenu");

	int menuNumber = 0;
	int difficult = 1;
	bool starting = false;

	Texture easyOff;
	easyOff.loadFromFile("buttonEasyOff.png");
	Texture easyOn;
	easyOn.loadFromFile("buttonEasyOn.png");
	Sprite easy;
	easy.setPosition(400, 100);



	Texture endT;
	endT.loadFromFile("buttonexitoff.png");
	Sprite end;
	end.setTexture(endT);
	end.setPosition(800, 200);//я знаю про классы, но пока только так

	Texture endTOn;
	endTOn.loadFromFile("buttonexiton.png");

	Texture startT;
	startT.loadFromFile("buttonplayoff.X9Wld.png");
	Sprite start;
	start.setTexture(startT);
	start.setPosition(800, 410);//я знаю про классы, но пока только так

	Texture startTOn;
	startTOn.loadFromFile("buttonplayon.1zhai.png");

	while (window4.isOpen()) {
		Event event;
		while (window4.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window4.close();
		}
		if (IntRect(800, 225, 100, 50).contains(Mouse::getPosition(window4))) {
			menuNumber = 1;
			end.setTexture(endTOn);
		}
		else if (IntRect(400, 100, 100, 50).contains(Mouse::getPosition(window4))) {
			menuNumber = 2;
			easy.setTexture(easyOn);
		}
		else if (IntRect(800, 435, 100, 50).contains(Mouse::getPosition(window4))) {
			start.setTexture(startTOn);
			starting = true;
		}

		else {
			easy.setTexture(easyOff);

			end.setTexture(endT);
			start.setTexture(startT);
			menuNumber = 0;
			starting = false;
		}
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (starting) {
				window4.close();
				trainingKeyboard();

			}
			if (menuNumber == 1) {
				window4.close();
				main();
			}
			if (menuNumber == 2) {
				difficult = menuNumber;
			}
		}
		window4.draw(start);
		window4.draw(easy);
		window4.display();
	}

}