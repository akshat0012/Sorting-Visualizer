#include <UI.hpp>
#include <vector>
#include <thread>
#include <util.hpp>
#include <sort.hpp>
#include <algorithm>
#include <SFML/Graphics.hpp>

int main() {   
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Project");

    Bars* BarsObject = new Bars();
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
                    
                    // seperate thread creation for bubbleSort function
                    std::thread t1([SortObject, &values, &window, &BarsObject]() {
                            SortObject->bubbleSort(values, window, BarsObject);
                    });
/*                     SortObject->bubbleSort(values, window, BarsObject);  */

                    t1.join();
                }

            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::R) {
                    RandomObject->randVec(values, 20, windowHeight-100);
                    window.clear();
                    BarsObject->drawVec(values, numberOfBars, window);
                    window.display();
                }
            }
            if (event.type == sf::Event::GainedFocus) {
                window.clear();
                BarsObject->drawVec(values, values.size(), window);
                window.display();
            }
            if (event.type == sf::Event::Resized) {
                // Adjust the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
                window.clear();
                BarsObject->drawVec(values, values.size(), window);
                window.display();
            }
        }
    }
    delete RandomObject;
    delete BarsObject;
    delete SortObject;
    return 0;
}
