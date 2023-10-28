#include <UI.hpp>
#include <vector>
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
    
    // define all the error bounding stuff here 
    window.setFramerateLimit(60);


    // DEFINE VARIABLES AND ALL THE DATA STRUCTURES
    std::vector<int> values(numberOfBars);

    // Print all the neccessary debugging information
    std::cout << numberOfBars << '\n';

    RandomObject->randVec(values, 100, windowHeight-100);
    UIObject->icon(window);

    delete RandomObject;
    delete UIObject;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        SortObject->bubbleSort(values, window, BarsObject);

        // window.clear(sf::Color(40, 40, 40));
        // BarsObject->drawVec(values, numberOfBars, window);
        // window.display();
        
    }

    delete BarsObject;
    delete SortObject;
    return 0;
}

