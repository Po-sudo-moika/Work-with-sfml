#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

using namespace sf;
using namespace std;

 int WIDTH =100, HEIGHT = 100, MAX_IT = 200, DEG = 1;
 double MAX_LEN = 2.0;
 int R = 255, G = 204, B = 204;
 int dR = 63, dG = 7, dB = 63;

double x1 = -1.6, __y1 = -1.6, x2 = 1.6, y2 = 1.6;
int main();

struct C_complex
{
    double a, b;
    C_complex(double _a = 0, double _b = 0)
    {
        a = _a;
        b = _b;
    }
    C_complex operator * (C_complex cur)
    {
        double c = cur.a;
        double d = cur.b;
        double _a = a * d + b * c;
        double _b = b * d - a * c;
        return C_complex(_a, _b);
    }
    C_complex operator + (C_complex cur)
    {
        return C_complex(a + cur.a, b + cur.b);
    }
    double get_len()
    {
        return sqrt(a * a + b * b);
    }
};

double get_x(int x)
{
    double res = (double)x * (x2 - x1);
    res /= WIDTH;
    return res + x1;
}

double get_y(int y)
{
    double res = (double)y * (y2 - __y1);
    res /= HEIGHT;
    return res + __y1;
}

void draw_point(sf::RenderWindow& window, int x, int y, int r, int g, int b) {
    sf::Vertex line[] =
    {
            sf::Vertex(sf::Vector2f(x, y), Color(r, g, b)),
            sf::Vertex(sf::Vector2f(x, y + 1), Color(r, g, b))
    };
    window.draw(line, 2, sf::Lines);
}

void draw_fractal(sf::RenderWindow& window, C_complex c_0)
{
    for (int i = 0; i < WIDTH; ++i)
        for (int j = 0; j < HEIGHT; ++j)
        {
            int cnt = MAX_IT;
            double x = get_x(i);
            double y = get_y(j);
            C_complex z(y, x), c(y, x);
            for (int it = 0; it < MAX_IT; ++it)
            {
                z = z*z*z  + c_0;
                if (z.get_len() >= MAX_LEN)
                {
                    cnt = it;
                    break;
                }
            }

            int r = 255 - 255 * cnt / MAX_IT;
            int g = 255 - 255 * cnt / MAX_IT;
            int b = 255 - 255 * cnt / MAX_IT;

            draw_point(window, i, j, r, g, b);
        }
}

int drawAnimation()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "fractal", sf::Style::Default, settings);

    int iterator = 56000000;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
                main();
            }
        }

        window.clear();
        draw_fractal(window, { (double)iterator / 100000000 * cos((double)iterator / 1000000), (double)iterator / 100000000 * sin((double)iterator / 1000000) });
        window.display();
        iterator += 100000;
    }

    return 0;
}
