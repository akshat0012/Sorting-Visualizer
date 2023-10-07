#include <SFML/Graphics.hpp>
#include <UI.hpp>
#include <vector>
#include <algorithm> 
#include <util.hpp>

Bars* BarsObject = new Bars();
sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Sorting Visualizer");

int main() {   

    UI* UIObject = new UI();
    randi* RandomObject = new randi();
        
    // DEFINE VARIABLES AND ALL THE DATA STRUCTURES
    std::vector<int> values(numberOfBars);

    // Print all the neccessary debugging information
    std::cout << numberOfBars << '\n';

    RandomObject->randVec(values, 100, windowHeight-100);
    sort(values.begin(), values.end());
    UIObject->icon(window);

    delete RandomObject;
    delete UIObject;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(40, 40, 40));
        BarsObject->drawVec(values, numberOfBars, window); 
        window.display();

    }

    delete BarsObject;
    return 0;
}
