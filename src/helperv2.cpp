#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

// Screen dimensions
const int screenWidth = 1000;
const int screenHeight = 1000;

// Number of bars and their dimensions
const int numBars = 100;
const int barWidth = screenWidth / numBars;
const int barMaxHeight = 500;

// Function to initialize the bars with random heights
std::vector<int> initializeBars() {
    std::vector<int> bars(numBars);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, barMaxHeight);

    for (int i = 0; i < numBars; ++i) {
        bars[i] = dis(gen);
    }
    return bars;
}


void drawBars(sf::RenderWindow& window, const std::vector<int>& bars, int highlight1 = -1, int highlight2 = -1) {
    for (int i = 0; i < numBars; ++i) {
        sf::RectangleShape bar(sf::Vector2f(barWidth - 1, bars[i]));
        bar.setPosition(i * barWidth, screenHeight - bars[i]);

        if (i == highlight1 || i == highlight2) { // Highlight elements being compared or swapped
            bar.setFillColor(sf::Color::Red);
        } else {
            bar.setFillColor(sf::Color::Blue);
        }
        window.draw(bar);

    }
}

// Bubble Sort Algorithm with highlighting swaps
void bubbleSort(std::vector<int>& bars, sf::RenderWindow& window) {
    int n = bars.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (bars[j] > bars[j + 1]) {
                std::swap(bars[j], bars[j + 1]);

                // Highlight the elements being compared and swapped
                window.clear();
                drawBars(window, bars, j, j + 1); // Highlight the elements being swapped
                window.display();
                sf::sleep(sf::milliseconds(1)); // Add a slight delay for visualization

                swapped = true;
            }
        }

        // If no elements were swapped, the array is already sorted
        if (!swapped)
            break;
    }
}



int main() {
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Sorting Visualizer");
    sf::Clock clock;

    std::vector<int> bars = initializeBars();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

/*         window.clear(); */
/*         drawBars(window, bars); */
/*         window.display(); */

        bubbleSort(bars, window);
    }

    return 0;
}

