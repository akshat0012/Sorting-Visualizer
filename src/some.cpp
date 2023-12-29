#include <SFML/Graphics.hpp>
#include <UI.hpp>
#include <util.hpp>
#include <vector>
#include <icon_data.h>

sf::Texture texture;
if (!texture.loadFromMemory(sfml_png)) {
    return 0;
}


int main() {

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Something else");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


    Bars* obj = new Bars();
    randi* robj = new randi(); 
    
    std::vector<int> values(numberOfBars);
    robj->randVec(values, 20, windowHeight-20);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    robj->randVec(values, 20, windowHeight-20);
                    robj->show(values);
                    window.clear();
                    obj->drawVec(values, values.size(), window);
                    window.display();
                }
            }
            if (event.type == sf::Event::GainedFocus) {
                window.clear();
                obj->drawVec(values, values.size(), window);
                window.display();
            }
            if (event.type == sf::Event::Resized) {
                // Adjust the view to the new size of the window
                std::cout << "H: " << event.size.height << "\n" << "W: " << event.size.width << "\n";
                std::cout << "Number of Bars -> " << numberOfBars << "\n";
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
                window.clear();
                obj->drawVec(values, values.size(), window);
                window.display();
            }
        }
    }
    return 0;
}
