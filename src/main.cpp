#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sorting Visualizer");

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    const int numBars = 20;
    std::vector<int> values(numBars);
    for (int i = 0; i < numBars; i++) {
        values[i] = 10 + std::rand() % 490; //10 ~490
    }

    //set bar width and gap
    const float barWidth = 30.f;
    const float gap = 5.f;

    //open window,keep checking if it's 'close' event
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);

        //Draw every bar
        for (int i = 0; i < numBars; i++) {
            sf::RectangleShape bar(sf::Vector2f(barWidth, static_cast<float>(values[i])));
            bar.setFillColor(sf::Color::Green);

            // bar 的位置：x 軸間隔排列，y 軸是從底部往上畫 (所以要往上偏移bar的高度)
            bar.setPosition(i * (barWidth + gap), 600 - values[i]);

            window.draw(bar);
        }
        window.display();
    }

    return 0;
}
