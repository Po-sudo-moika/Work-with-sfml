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

void pianino() {

	RenderWindow window1(sf::VideoMode(1376, 726), "Pianino");


	if (!SoundBufferRecorder::isAvailable()) {

	}
	SoundBufferRecorder recording;



	int button = 0;

	RectangleShape button1;
	button1.setSize(Vector2f(50, 400));
	button1.setOutlineColor(sf::Color::Green);
	button1.setOutlineThickness(2);
	button1.setPosition(672, 100);
	button1.setFillColor(Color::White);



	RectangleShape button8;
	button8.setSize(Vector2f(50, 300));
	button8.setOutlineColor(sf::Color::Green);
	button8.setOutlineThickness(2);
	button8.setPosition(620, 100);
	button8.setFillColor(Color::Black);


	RectangleShape button2;
	button2.setSize(Vector2f(50, 400));
	button2.setOutlineColor(sf::Color::Green);
	button2.setOutlineThickness(2);
	button2.setPosition(568, 100);
	button2.setFillColor(Color::White);


	RectangleShape button9;
	button9.setSize(Vector2f(50, 300));
	button9.setOutlineColor(sf::Color::Green);
	button9.setOutlineThickness(2);
	button9.setPosition(516, 100);
	button9.setFillColor(Color::Black);



	RectangleShape button3;
	button3.setSize(Vector2f(50, 400));
	button3.setOutlineColor(sf::Color::Green);
	button3.setOutlineThickness(2);
	button3.setPosition(464, 100);
	button3.setFillColor(Color::White);


	RectangleShape button10;
	button10.setSize(Vector2f(50, 300));
	button10.setOutlineColor(sf::Color::Green);
	button10.setOutlineThickness(2);
	button10.setPosition(412, 100);
	button10.setFillColor(Color::Black);



	RectangleShape button4;
	button4.setSize(Vector2f(50, 400));
	button4.setOutlineColor(sf::Color::Green);
	button4.setOutlineThickness(2);
	button4.setPosition(360, 100);
	button4.setFillColor(Color::White);



	RectangleShape button5;
	button5.setSize(Vector2f(50, 400));
	button5.setOutlineColor(sf::Color::Green);
	button5.setOutlineThickness(2);
	button5.setPosition(308, 100);
	button5.setFillColor(Color::White);



	RectangleShape button11;
	button11.setSize(Vector2f(50, 300));
	button11.setOutlineColor(sf::Color::Green);
	button11.setOutlineThickness(2);
	button11.setPosition(256, 100);
	button11.setFillColor(Color::Black);



	RectangleShape button6;
	button6.setSize(Vector2f(50, 400));
	button6.setOutlineColor(sf::Color::Green);
	button6.setOutlineThickness(2);
	button6.setPosition(204, 100);


	RectangleShape button12;
	button12.setSize(Vector2f(50, 300));
	button12.setOutlineColor(sf::Color::Green);
	button12.setOutlineThickness(2);
	button12.setPosition(152, 100);
	button12.setFillColor(Color::Black);



	RectangleShape button7;
	button7.setSize(Vector2f(50, 400));
	button7.setOutlineColor(sf::Color::Green);
	button7.setOutlineThickness(2);
	button7.setPosition(100, 100);//я знаю про классы, но пока только так
	button7.setFillColor(Color::White);

	Texture endT;
	endT.loadFromFile("buttonexitoff.png");
	Sprite end;
	end.setTexture(endT);
	end.setPosition(800, 200);//я знаю про классы, но пока только так

	Texture endTOn;
	endTOn.loadFromFile("buttonexiton.png");

	Texture recordT;
	recordT.loadFromFile("buttonrecordstart.b0Dx7.png");
	Sprite record;
	record.setTexture(recordT);
	record.setPosition(800, 270);//я знаю про классы, но пока только так

	Texture recordendT;
	recordendT.loadFromFile("buttonrecordstop.1iBkW.png");
	Sprite recordend;
	recordend.setTexture(recordendT);
	recordend.setPosition(800, 340);//я знаю про классы, но пока только так

	Texture startT;
	startT.loadFromFile("buttonplayoff.X9Wld.png");
	Sprite start;
	start.setTexture(startT);
	start.setPosition(800, 410);//я знаю про классы, но пока только так

	Texture startTOn;
	startTOn.loadFromFile("buttonplayon.1zhai.png");


	SoundBuffer doB;
	doB.loadFromFile("do.ogg");
	Sound doS;
	doS.setBuffer(doB);
	doS.setLoop(true);

	SoundBuffer doreB;
	doreB.loadFromFile("dore.ogg");
	Sound doreS;
	doreS.setBuffer(doreB);
	doreS.setLoop(true);

	SoundBuffer reB;
	reB.loadFromFile("re.ogg");
	Sound reS;
	reS.setBuffer(reB);
	reS.setLoop(true);

	SoundBuffer remiB;
	remiB.loadFromFile("remi.ogg");
	Sound remiS;
	remiS.setBuffer(remiB);
	remiS.setLoop(true);

	SoundBuffer miB;
	miB.loadFromFile("mi.ogg");
	Sound miS;
	miS.setBuffer(miB);
	miS.setLoop(true);

	SoundBuffer faB;
	faB.loadFromFile("fa.ogg");
	Sound faS;
	faS.setBuffer(faB);
	faS.setLoop(true);

	SoundBuffer facolB;
	facolB.loadFromFile("facol.ogg");
	Sound facolS;
	facolS.setBuffer(facolB);
	facolS.setLoop(true);

	SoundBuffer colB;
	colB.loadFromFile("col.ogg");
	Sound colS;
	colS.setBuffer(colB);
	colS.setLoop(true);

	SoundBuffer collyaB;
	collyaB.loadFromFile("collya.ogg");
	Sound collyaS;
	collyaS.setBuffer(collyaB);
	collyaS.setLoop(true);

	SoundBuffer lyaB;
	lyaB.loadFromFile("lya.ogg");
	Sound lyaS;
	lyaS.setBuffer(lyaB);
	lyaS.setLoop(true);

	SoundBuffer lyaciB;
	lyaciB.loadFromFile("lyaci.ogg");
	Sound lyaciS;
	lyaciS.setBuffer(lyaciB);
	lyaciS.setLoop(true);

	SoundBuffer ciB;
	ciB.loadFromFile("ci.ogg");
	Sound ciS;
	ciS.setBuffer(ciB);
	ciS.setLoop(true);

	Music myRecord;
	myRecord.openFromFile("my_record.ogg");

	Font font;
	font.loadFromFile("font.ttf");

	Text text("", font, 28);
	text.setPosition(100, 600);
	text.setString(L"Клавиши для игры:'a,s,d,f,g,h,j,q,w,e,r,t,y'");

	bool playing = true;
	bool doMarker = true;
	bool doreMarker = true;
	bool reMarker = true;
	bool remiMarker = true;
	bool miMarker = true;
	bool faMarker = true;
	bool facolMarker = true;
	bool colMarker = true;
	bool collyaMarker = true;
	bool lyaMarker = true;
	bool lyaciMarker = true;
	bool ciMarker = true;
	bool recorder = false;

	window1.setKeyRepeatEnabled(false);
	while (playing) {
		Event event;
		while (window1.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window1.close();
		}
		window1.clear(Color(0, 0, 0));
		if (IntRect(800, 225, 100, 50).contains(Mouse::getPosition(window1))) {
			button = 1;
			end.setTexture(endTOn);
		}
		else if (IntRect(825, 295, 50, 50).contains(Mouse::getPosition(window1))) {
			button = 2;
			record.setColor(Color(255, 100, 255, 255));
		}
		else if (IntRect(825, 365, 50, 50).contains(Mouse::getPosition(window1))) {
			button = 3;
			recordend.setColor(Color(100, 255, 255, 255));
		}
		else if (IntRect(800, 425, 100, 50).contains(Mouse::getPosition(window1))) {
			button = 4;
			start.setTexture(startTOn);

		}
		else
		{
			record.setColor(Color(255, 255, 255, 255));
			recordend.setColor(Color(255, 255, 255, 255));
			start.setTexture(startT);
			end.setTexture(endT);
			button = 0;
		}
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (button == 1) {
				window1.close();
				main();
			}
			if (button == 2) {
				if (recorder == false) {
					recorder = true;
					recording.start();
				}

			}
			if (button == 3) {
				if (recorder == true) {
					recorder = false;
					recording.stop();
					const sf::SoundBuffer& buffer = recording.getBuffer();
					buffer.saveToFile("my_record.ogg");

				}
			}
			if (button == 4) {
				myRecord.play();
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::J)) {
			button1.setFillColor(Color(50, 50, 50));
			if (doMarker) {
				doS.play();
				doMarker = false;
			}
		}
		else { button1.setFillColor(Color::White); doMarker = true; doS.stop(); doS.setLoop(false); }
		if (Keyboard::isKeyPressed(Keyboard::H)) {
			button2.setFillColor(Color(50, 50, 50));
			if (reMarker) {
				reS.play();
				reMarker = false;
			}
		}
		else { button2.setFillColor(Color::White); reMarker = true; reS.stop(); reS.setLoop(false); }

		if (Keyboard::isKeyPressed(Keyboard::G)) {
			button3.setFillColor(Color(50, 50, 50));
			if (miMarker) {
				miS.play();
				miMarker = false;
			}
		}
		else { button3.setFillColor(Color::White); miMarker = true; miS.stop(); miS.setLoop(false); }

		if (Keyboard::isKeyPressed(Keyboard::F)) {
			button4.setFillColor(Color(50, 50, 50));
			if (faMarker) {
				faS.play();
				faMarker = false;
			}
		}
		else { button4.setFillColor(Color::White); faMarker = true; faS.stop(); faS.setLoop(false); }

		if (Keyboard::isKeyPressed(Keyboard::D)) {
			button5.setFillColor(Color(50, 50, 50));
			if (colMarker) {
				colS.play();
				colMarker = false;
			}
		}
		else { button5.setFillColor(Color::White); colMarker = true; colS.stop(); colS.setLoop(false); }

		if (Keyboard::isKeyPressed(Keyboard::S)) {
			button6.setFillColor(Color(50, 50, 50));
			if (lyaMarker) {
				lyaS.play();
				lyaMarker = false;
			}
		}
		else { button6.setFillColor(Color::White); lyaMarker = true; lyaS.stop(); lyaS.setLoop(false); }

		if (Keyboard::isKeyPressed(Keyboard::A)) {
			button7.setFillColor(Color(50, 50, 50));
			if (ciMarker) {
				ciS.play();
				ciMarker = false;
			}
		}
		else { button7.setFillColor(Color::White); ciMarker = true; ciS.stop(); ciS.setLoop(false); }

		if (Keyboard::isKeyPressed(Keyboard::Y)) {
			button8.setFillColor(Color(20, 20, 20));
			if (doreMarker) {
				doreS.play();
				doreMarker = false;
			}
		}
		else { button8.setFillColor(Color::Black); doreMarker = true; doreS.stop(); doreS.setLoop(false); }

		if (Keyboard::isKeyPressed(Keyboard::T)) {
			button9.setFillColor(Color(20, 20, 20));
			if (remiMarker) {
				remiS.play();
				remiMarker = false;
			}
		}
		else { button9.setFillColor(Color::Black); remiMarker = true; remiS.stop(); remiS.setLoop(false); }

		if (Keyboard::isKeyPressed(Keyboard::R)) {
			button10.setFillColor(Color(20, 20, 20));
			if (facolMarker) {
				facolS.play();
				facolMarker = false;
			}
		}
		else { button10.setFillColor(Color::Black); facolMarker = true; facolS.stop(); facolS.setLoop(false); }

		if (Keyboard::isKeyPressed(Keyboard::E)) {
			button11.setFillColor(Color(20, 20, 20));
			if (collyaMarker) {
				collyaS.play();
				collyaMarker = false;
			}
		}
		else { button11.setFillColor(Color::Black); collyaMarker = true; collyaS.stop(); collyaS.setLoop(false); }

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			button12.setFillColor(Color(20, 20, 20));
			if (lyaciMarker) {
				lyaciS.play();
				lyaciMarker = false;
			}
		}
		else { button12.setFillColor(Color::Black); lyaciMarker = true; lyaciS.stop(); lyaciS.setLoop(false); }

		window1.draw(button1);
		window1.draw(button2);
		window1.draw(button3);
		window1.draw(button4);
		window1.draw(button5);
		window1.draw(button6);
		window1.draw(button7);
		window1.draw(button8);
		window1.draw(button9);
		window1.draw(button10);
		window1.draw(button11);
		window1.draw(button12);
		window1.draw(end);
		window1.draw(record);
		window1.draw(recordend);
		window1.draw(start);
		window1.draw(text);

		window1.display();
	}
}