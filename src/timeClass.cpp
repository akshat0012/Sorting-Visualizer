#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
/*
 *  BASIC HELLO WORLD TEMPLATE
 */

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    window.setFramerateLimit(60);
    
    auto image = sf::Image{};
    if(!image.loadFromFile("./images/jetbrainsRider/icons8-rider-jetbrains-96.png")) {
        std::cout << "Error Loading image\n";
    }
    window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());


    // Text
    sf::Font font;
    font.loadFromFile("./fonts/blox/Blox2.ttf");
    sf::Text text("Time Class", font, 110);

    sf::Clock clock;


    // Game Loop
    while (window.isOpen()) { 
        float currentTime = clock.restart().asSeconds();
        float fps = 1.0f / (currentTime);
    
        std::cout << "fps: " << fps << "\n";

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();

        window.draw(text);

        window.display();
    }

    return 0;
}
