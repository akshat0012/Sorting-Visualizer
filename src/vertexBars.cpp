#include <SFML/Graphics.hpp>
#include <UI.hpp>
#include <vector>
#include <algorithm> 
#include <util.hpp>

Bars* BarsObject = new Bars();
sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Generate Bars");

int main() {   

    // DEFINE OBJECTS OF CLASSES HERE. 

    // Bars* BarsObject = new Bars();
    UI* UIObject = new UI();
    randi* RandomObject = new randi();
    
    // DEFINE VARIABLES AND ALL THE DATA STRUCTURES
    std::vector<int> values(numberOfBars);

    // Print all the neccessary debugging information
    std::cout << numberOfBars << '\n';

    RandomObject->randVec(values, 100, windowHeight-100);
    // sort(values.begin(), values.end());
    BarsObject->drawVec(values, numberOfBars);
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
        BarsObject->drawBars(window); 
        window.display();
    }

    delete BarsObject;
    return 0;
}

