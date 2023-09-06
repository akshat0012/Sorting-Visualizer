#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

const int barWidth = 2;
const int windowWidth = 1000;
const int windowHeight = 1000;
const int numberOfBars = windowWidth / barWidth;


void drawText(std::string txt, sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("./fonts/blox/Blox2.ttf")) {
        std::cout << "Error loading font\n";
    };

    sf::Text text(txt, font, 110);
    window.draw(text);
}

void random(int _min, int _max, int numberOfValues, std::vector<int>& heights) {
    std::random_device rd; // random number for seeding
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distr(_min, _max); 
    for (int i=0; i<numberOfValues; i++) {
        heights.push_back(distr(gen));
    }
}


void drawBars(std::vector<int>& heights, sf::RenderWindow& window, int firstBar, int secondBar) { // This function is drawing the state of the array
    int posX = 0;
    for (int h=0; h<heights.size(); h++) {
        sf::RectangleShape rect;
        // set the attributes of the rectangle
        rect.setSize(sf::Vector2f(barWidth-1, heights[h])); // -2 for the border like effect
        
        if (firstBar == -1 && secondBar == -1) rect.setFillColor(sf::Color::White);

        if (h == firstBar || h == secondBar) rect.setFillColor(sf::Color::Red);

        rect.setPosition(posX, windowHeight-heights[h]);

        // draw the rectangle
        window.draw(rect);

        // update the position at y axis for the next Bar.
        posX += barWidth;
    }
}


class algorithms {
public:

    // bubble sort starts here
    bool bubbleSort(std::vector<int>& heights, sf::RenderWindow& window) {
        
        int n = heights.size();
        
        for (int i=0; i<n; i ++) {
    
            bool swaped = false;

            for (int j=0; j<n-i-1; j++) {
                if (heights[j] > heights[j+1]) {
                    std::swap(heights[j], heights[j+1]);
                
                    // display the new state of the bars after updating the array.
                    window.clear();
                    drawBars(heights, window, j, j+1);
                    window.display();
                    swaped = true;

                }
            }
            if (!swaped) {
                break;
            }
        }
        window.clear();
        drawBars(heights, window, -1, -1);
        window.display();

        return true;
    }
    // bubble sort ends here
};




int main()
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Sorting Visualizer");


    auto image = sf::Image{};
    image.loadFromFile("./assets/bar-chart.png");
    window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());


    std::vector<int> heights;
    random(10, 900, numberOfBars, heights);
    algorithms object1;
    
    object1.bubbleSort(heights, window);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
            
    }
    return 0;
}
