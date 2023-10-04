#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm> 
#include <iostream>

const int windowWidth = 1000;
const int windowHeight = 1000;


sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "framerate");


int main() {   
    
    unsigned int fCount = 0;
    
    float fps;
    sf::Clock clock;
    sf::Time previousTime = clock.getElapsedTime();
    sf::Time currentTime = sf::Time::Zero;

    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        currentTime = clock.getElapsedTime();
        fps = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds()); // the asSeconds returns a float
        std::cout << "FPS: " << fps <<  '\n'; // flooring it will make the frame rate a rounded number
        previousTime = currentTime;

        window.clear(sf::Color(40, 40, 40));
        window.display();
    }

    return 0;
}

