#include <SFML/Graphics.hpp>

const int windowHeight = 1000;
const int windowWidth = 1000;
const int barWidth = 500;
const int barHeight = 500;

int main()
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Vertex Buffers and Arrays");
    window.setFramerateLimit(60);

    sf::VertexArray SquareWithLines(sf::TriangleFan, 4);
    SquareWithLines[0].position = sf::Vector2f(100, barHeight); // A coordintes for the Sqaure. 
    SquareWithLines[1].position = sf::Vector2f(100, windowHeight); 
    SquareWithLines[2].position = sf::Vector2f(200, windowHeight);
    SquareWithLines[3].position = sf::Vector2f(200, barHeight); // B coordinated for the Square.
    
    SquareWithLines[0].color = sf::Color::Red; // A coordintes for the Sqaure.
    SquareWithLines[3].color = sf::Color::White;
    SquareWithLines[1].color = sf::Color::Green; 
    SquareWithLines[2].color = sf::Color::Blue;
    /* SquareWithLines[3].color = sf::Color::White; // B coordinated for the Square. */
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        /* window.draw(colouredSquare, 3, sf::TriangleFan); */
        window.draw(SquareWithLines);
        window.display();
    }

    return 0;
}
