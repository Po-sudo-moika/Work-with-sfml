#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <locale.h>
#include "pianino.h"
#include "KeyboardMenu.h"
#include "KeyboardTraining.h"
#include "LogOtvet.h"

using namespace sf;
using namespace std;

int main();

void aboutMe() {
	RenderWindow window(sf::VideoMode(1376, 726), "AboutMe");
	Font font;
	font.loadFromFile("font.ttf");

	Text text("", font, 28);
	text.setPosition(550, 200);

	Texture endT;
	endT.loadFromFile("buttonexitoff.png");
	Sprite end;
	end.setTexture(endT);
	end.setPosition(300, 200);//я знаю про классы, но пока только так
	Texture endTOn;
	endTOn.loadFromFile("buttonexiton.png");


	while (window.isOpen()) {
		text.setString(L"Категорически вас приветствую\n Зовут меня: Кичигин Михаил\n Учусь в группе ИВТ-191\n По заверению проверенных камрадов пошел на программиста\n Ощущения - АТАС\n Сейчас хочу только одно - получить стипендию");
		window.draw(text);
		if (IntRect(300, 225, 100, 50).contains(Mouse::getPosition(window))) {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				window.close();
				main();
			}
			end.setTexture(endTOn);
		}
		else end.setTexture(endT);
		window.draw(end);
		window.display();
	}
}