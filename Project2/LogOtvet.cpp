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
void logOtvet(int second, float mistakes, float score) {
	RenderWindow window5(sf::VideoMode(600, 600), "LOG");
	ostringstream otvet;
	string statistic;


	ifstream file("C:\\textforkursach\\easy.txt", ios::in);
	Font font;
	font.loadFromFile("font.ttf");

	Text pomogite("", font, 20);
	pomogite.setPosition(100, 50);

	Text pomogite2("", font, 20);
	pomogite.setPosition(100, 100);

	float speedKey;
	float percentOfQuality;
	speedKey = (score + mistakes) / second;
	percentOfQuality = (mistakes / (score + mistakes)) * 100;

	Texture endT;
	endT.loadFromFile("buttonexitoff.png");
	Sprite end;
	end.setTexture(endT);
	end.setPosition(300, 200);//я знаю про классы, но пока только так
	Texture endTOn;
	endTOn.loadFromFile("buttonexiton.png");

	while (window5.isOpen()) {
		Event event;
		while (window5.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window5.close();
		}
		window5.clear();
		if (IntRect(300, 225, 100, 50).contains(Mouse::getPosition(window5))) {
			end.setTexture(endTOn);
			if (Mouse::isButtonPressed(Mouse::Left)) {
				window5.close();
				main();
			}
		}
		else end.setTexture(endT);

		otvet << speedKey;
		otvet << " - keys per second                                        ";
		statistic = otvet.str();
		window5.draw(pomogite);
		otvet.str("");

		otvet << percentOfQuality;
		otvet << "% - mistakes";
		pomogite.setString(statistic);

		statistic = otvet.str();
		pomogite2.setString(statistic);
		pomogite2.setPosition(100, 200);
		window5.draw(pomogite2);
		otvet.str("");
		window5.draw(end);
		window5.display();
	}
}