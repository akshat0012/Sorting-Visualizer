#include <iostream>
#include <vector>
#include <unistd.h>
#include <SFML/Graphics.hpp>

#ifndef UI_hpp
#define UI_hpp

const int windowHeight = 1080/2;
const int windowWidth = 1920/2;
const int barWidth = 10;
const int numberOfBars = (windowWidth / barWidth);

class UI {  
public:
    // This functions set the window Icon
    void icon(sf::RenderWindow& window) {
		std::string username = getlogin();
		std::string path = "/home/" + username + "/github-repo/Sorting-Visualizer/assets/images/sfml.png";
        auto image = sf::Image{};
        if (!image.loadFromFile("/home/rabbit/github-repo/Sorting-Visualizer/assets/images/sfml.png"))
        {
            // Error handling...
            std::cout << "Error in loading the file\n";
        }
        window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
    }

    // Destructor
    ~UI() {
        std::cout << "[UI_object_deleted]\n";
    }
};

class Bars {
private:
    sf::VertexArray bar;
public:

    // Constructor
    Bars() : bar(sf::Quads, (windowWidth / barWidth)*4) {};

    void whereAmI() {
        std::cout << "inside_Bars_hpp\n";
    }
    
    void createBar() { 
        // the anatomy is in U shape 0 1 2 3 cordinates
        bar[0].position = sf::Vector2f(0, 100);
        bar[1].position = sf::Vector2f(0, windowHeight);
        bar[2].position = sf::Vector2f(barWidth, windowHeight);
        bar[3].position = sf::Vector2f(barWidth, 100);

    }

    void drawVec(std::vector<int>& vec, int numberOfBars, sf::RenderWindow& window) {
        for (int i = 0; i < numberOfBars; i++) {
            int barHeight = vec[i];

            bar[i * 4].position = sf::Vector2f(i * barWidth + 2, windowHeight); // Bottom-left
            bar[i * 4 + 1].position = sf::Vector2f((i + 1) * barWidth, windowHeight); // Bottom-right
            bar[i * 4 + 2].position = sf::Vector2f((i + 1) * barWidth, windowHeight - barHeight); // Top-right
            bar[i * 4 + 3].position = sf::Vector2f(i * barWidth + 2, windowHeight - barHeight); // Top-left
 

            bar[i * 4].color = sf::Color(131, 165, 152);
            bar[i * 4 + 1].color = sf::Color(131, 165, 152);
            bar[i * 4 + 2].color = sf::Color(131, 165, 152);
            bar[i * 4 + 3].color = sf::Color(131, 165, 152);
        }
        window.draw(bar);
    }
    

    // Destructor
    ~Bars() {
        std::cout << "[BarsObject_deleted]\n";
    }

};

#endif
