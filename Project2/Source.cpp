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
#include "Menu.h"
#include "Anime.h"


using namespace sf;
using namespace std;

int main()
{

	setlocale(LC_ALL, "RUS");
	menu();

	return 0;
}