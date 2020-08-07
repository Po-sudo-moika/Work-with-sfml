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
#include "AboutMe.h"
#include "Anime.h"

using namespace sf;
using namespace std;

int menu() {
	sf::RenderWindow window(sf::VideoMode(1376, 726), "GlMenu");
	int numMenu = 0;
	bool menuWork = true;


	Texture pianoT;
	pianoT.loadFromFile("buttonpianooff.xK08f.png");
	Texture pianoTOn;
	pianoTOn.loadFromFile("buttonpianoon.74kLl.png");
	Texture keyboardT;
	keyboardT.loadFromFile("buttonkeyboardoff.png");
	Texture keyboardTOn;
	keyboardTOn.loadFromFile("buttonkeyboardon.png");
	Texture exitT;
	exitT.loadFromFile("buttonexitoff.png");
	Texture	exitTOn;
	exitTOn.loadFromFile("buttonexiton.png");
	Texture animeOff;
	animeOff.loadFromFile("buttonAnimeOff.png");
	Texture animeOn;
	animeOn.loadFromFile("buttonAnimeOn.png");
	Texture aboutOff;
	aboutOff.loadFromFile("buttonMeOff.png");
	Texture aboutOn;
	aboutOn.loadFromFile("buttonMeOn.png");


	Sprite piano;
	piano.setPosition(600, 300);
	Sprite training;
	training.setPosition(600, 400);
	Sprite exit;
	exit.setPosition(600, 500);
	Sprite anime;
	anime.setPosition(600, 200);
	Sprite me;
	me.setPosition(600, 100);

	while (menuWork) {
		window.clear(Color(0, 0, 0));
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (IntRect(600, 325, 100, 50).contains(Mouse::getPosition(window))) {
			piano.setTexture(pianoTOn);
			numMenu = 1;
			training.setTexture(keyboardT);
			exit.setTexture(exitT);
			me.setTexture(aboutOff);
			anime.setTexture(animeOff);
		}
		else if (IntRect(600, 425, 100, 50).contains(Mouse::getPosition(window))) {
			training.setTexture(keyboardTOn);
			numMenu = 2;
			piano.setTexture(pianoT);
			exit.setTexture(exitT);
			me.setTexture(aboutOff);
			anime.setTexture(animeOff);
		}
		else if (IntRect(600, 525, 100, 50).contains(Mouse::getPosition(window))) {
			exit.setTexture(exitTOn);
			numMenu = 3;
			piano.setTexture(pianoT);
			training.setTexture(keyboardT);
			me.setTexture(aboutOff);
			anime.setTexture(animeOff);
		}
		else if (IntRect(600, 200, 100, 50).contains(Mouse::getPosition(window))) {
			anime.setTexture(animeOn);
			numMenu = 4;
			piano.setTexture(pianoT);
			training.setTexture(keyboardT);
			exit.setTexture(exitT);
			me.setTexture(aboutOff);
		}
		else if (IntRect(600, 100, 100, 50).contains(Mouse::getPosition(window))) {
			me.setTexture(aboutOn);
			numMenu = 5;
			piano.setTexture(pianoT);
			training.setTexture(keyboardT);
			exit.setTexture(exitT);
			anime.setTexture(animeOff);
		}
		else {
			numMenu = 0;
			piano.setTexture(pianoT);
			training.setTexture(keyboardT);
			exit.setTexture(exitT);
			me.setTexture(aboutOff);
			anime.setTexture(animeOff);
		}
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (numMenu == 1) { window.close(); pianino(); }
			if (numMenu == 2) { window.close(); trainingKeyboardMenu(); }
			if (numMenu == 3) { window.close(); }
			if (numMenu == 4) { window.close(); drawAnimation(); }
			if (numMenu == 5) { window.close(); aboutMe(); }
		}
		window.draw(exit);
		window.draw(training);
		window.draw(piano);
		window.draw(anime);
		window.draw(me);

		window.display();
	}


	return 0;
}