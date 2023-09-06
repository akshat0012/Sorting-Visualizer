#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <thread>

const int windowWidth = 1000;
const int windowHeight = 1000;
const int numBars = 500; // Number of bars to sort
const int barWidth = windowWidth / numBars;
const int barMaxHeight = windowHeight - 100;

void drawBars(sf::RenderWindow& window, const std::vector<int>& arr) {
    window.clear();

    for (size_t i = 0; i < arr.size(); ++i) {
        sf::RectangleShape bar(sf::Vector2f(barWidth, arr[i]));
        bar.setPosition(i * barWidth, windowHeight - arr[i]);
        window.draw(bar);
    }

    window.display();
}

void bubbleSort(std::vector<int>& arr, sf::RenderWindow& window) {
    bool swapped;
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
                // Visualization: Draw the bars after every swap
                // Comment this line for faster sorting without visualization
                drawBars(window, arr);
                // std::this_thread::sleep_for(std::chrono::milliseconds(1/4));
            }
        }
        // If no two elements were swapped in the inner loop, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Sorting Visualizer");

    std::vector<int> arr;
    // Generate random numbers for the initial array
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, barMaxHeight);
    for (int i = 0; i < numBars; ++i) {
        arr.push_back(dis(gen));
    }

    bubbleSort(arr, window); // Call your sorting algorithm here

    // Keep the window open until it is closed
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    return 0;
}

