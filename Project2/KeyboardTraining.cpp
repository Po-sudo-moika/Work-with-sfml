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
void logOtvet(int second, float mistakes, float score);

int trainingKeyboard() {
	RenderWindow window2(sf::VideoMode(1376, 726), "Training");
	bool answer = true;
	char* symbol = 0;
	int x = 200;
	int i = 0;
	int n = 267;
	float score = 0;
	char help = 0;
	int second = 0;
	int minets = 0;
	float mistakes = 0;

	ifstream file("easy.txt", ios::in);
	Font font;
	font.loadFromFile("font.ttf");

	Text text("", font, 20);
	text.setPosition(x, 200);

	Time time;
	Clock clock;
	size_t length = 0;
	char* buf = 0;
	Text timer("", font, 20);
	timer.setPosition(900, 200);
	string chas;



	for (int i = 0; i < n; i++) {
		if (file.is_open())
		{
			file.seekg(0, ios::end);
			length = file.tellg();
			file.seekg(0, ios::beg);
			buf = new char[1 + length];
			buf[length] = 0;
			for (int i = 0; i < length + 1; i++)
			{
				buf[i] = file.get();
			}
			file.close();
		}
	}
	ostringstream secundomer;
	Event event;
	while (window2.isOpen()) {
		time = clock.getElapsedTime();

		window2.clear();
		while (x < 800) {
			text.setString(buf[i]);
			x += 25;
			text.setPosition(x, 200);
			window2.draw(text);
			i++;



		}
		if (Keyboard::isKeyPressed(Keyboard::Enter)) {
			window2.close();
			logOtvet(second, mistakes, score);
		}
		while (window2.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window2.close();
			}
			if (event.type == Event::KeyPressed) {
				help = event.key.code + 65;
				if (help == 'r') {
					help = ',';
				}
				if (help == 's') {
					help = '.';		// switch не работает и выводит точку вне зависимости от нажатой клавиши
				}				   // В sfml кодировка AS3, а я перевожу в ASII
				if (help == 'z') {
					help = ' ';
				}
				if (help == '/') {
					help = '1';
				}
				if (help == ']') {
					help = '2';
				}
				if (help == '^') {
					help = '3';
				}
				if (help == '_') {
					help = '4';
				}
				if (help == '`') {
					help = '5';
				}
				if (help == 'a') {
					help = '6';
				}
				if (help == 'b') {
					help = '7';
				}
				if (help == 'c') {
					help = '8';
				}
				if (help == 'd') {
					help = '9';
				}
				if (help == '[') {
					help = '0';
				}
				if (help == buf[0]) {
					score++;
					for (int f = 0; f < n + 1; f++) {
						buf[f] = buf[f + 1];
					}
				}
				else {
					mistakes++;
				}
				n--;

			}

		}


		second = time.asSeconds();

		secundomer << second;
		chas = secundomer.str();
		timer.setString(chas);
		window2.draw(timer);
		secundomer.str("");

		i = 0;
		x = 200;

		window2.display();
	}
	return 0;
}