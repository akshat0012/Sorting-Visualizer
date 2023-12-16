#include <UI.hpp>
#include <vector>
#include <thread>
#include <util.hpp>
#include <sort.hpp>
#include <algorithm>
#include <SFML/Graphics.hpp>

Bars* BarsObject = new Bars();
sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Project");

int main() {   

    UI* UIObject = new UI();
    randi* RandomObject = new randi();
    Sort* SortObject = new Sort();

    // DEFINE VARIABLES AND ALL THE DATA STRUCTURES
    std::vector<int> values(numberOfBars);

    // Print all the neccessary debugging information
    std::cout << numberOfBars << '\n';

    RandomObject->randVec(values, 20, windowHeight-100);
    UIObject->icon(window);
    // BarsObject->drawVec(values, numberOfBars, window);

    delete RandomObject;
    delete UIObject;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::S) {
                    SortObject->bubbleSort(values, window, BarsObject);
                }
            }

        }
        /* SortObject->bubbleSort(values, window, BarsObject); */
        // BarsObject->drawVec(values, numberOfBars, window);
    }
   
    delete BarsObject;
    delete SortObject;
    return 0;
}
