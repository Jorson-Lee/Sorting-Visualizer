#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <utility>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>   // std::this_thread::sleep_for
#include <chrono>   // std::chrono::milliseconds

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

    int i = 0, j = 0;
    bool sorted = false;
    //main sorting loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if (!sorted) {
            if (i < numBars) {
                if (j < numBars - i - 1) {
                    if (values[j] > values[j + 1]) {
                        std::swap(values[j], values[j + 1]);
                    }
                    j++;
                } else {
                    i++;
                    j = 0;
                }
            } else {
                sorted = true;
            }
        }
        //畫面更新
        window.clear(sf::Color::Black);


        //Draw every bar
        for (int k = 0; k < numBars; k++) {
            sf::RectangleShape bar(sf::Vector2f(barWidth, static_cast<float>(values[k])));
            // 決定顏色順序：藍色 > 紅色 > 綠色
            if (k == numBars - i - 1 && !sorted) {
                // 已確定排好、剛冒泡完成的最大值
                bar.setFillColor(sf::Color::Blue);
            } else if (k == j || (k == j + 1 && k < numBars - i - 1)) {
                // 目前正在比較的兩個元素
                bar.setFillColor(sf::Color::Red);
            } else {
                // 其他
                bar.setFillColor(sf::Color::Green);
            }
            // bar 的位置：x 軸間隔排列，y 軸是從底部往上畫 (所以要往上偏移bar的高度)
            bar.setPosition(k * (barWidth + gap), 600 - values[k]);

            window.draw(bar);
        }
        window.display();

        // 每步動畫延遲（控制速度）
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }


    return 0;
}
