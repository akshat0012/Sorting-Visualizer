#include <SFML/Graphics.hpp>
#include <cmath> // For easing function
#include <random> // For random number generation

const float windowHeight = 1000;
const float windowWidth = 1000;
const float barWidth = 8;
const float numberOfBars = windowWidth / barWidth;

// Easing function: Quadratic easeInOut
float easeInOutQuad(float t) {
    t *= 2.0f;
    if (t < 1.0f)
        return 0.5f * t * t;
    t -= 1.0f;
    return -0.5f * (t * (t - 2.0f) - 1.0f);
}

void drawBars(sf::RenderWindow& window, int n) {
    const float barWidth = 8.0f;
    const float minHeight = 0.0f;
    const float maxHeight = 1000.0f;
    const float animationDuration = 0.5f;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(minHeight, maxHeight);

    std::vector<sf::RectangleShape> bars(n);
    std::vector<float> targetHeights(n); // Store target heights for each bar
    int positionX = 0;    
    for (int i = 0; i < n; i++) {
        float randomHeight = dis(gen);
        targetHeights[i] = randomHeight;
        bars[i].setSize(sf::Vector2f(barWidth-2, 0.0f)); // Start with height 0
        bars[i].setFillColor(sf::Color::Red);
        bars[i].setPosition(positionX, windowHeight - targetHeights[i]);
    }

    sf::Clock clock;
    float elapsedTime = 0.0f;

    while (true) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update the animation
        elapsedTime = clock.getElapsedTime().asSeconds();
        float t = std::min(elapsedTime / animationDuration, 1.0f); // Ensure t doesn't go beyond 1
        float easedT = easeInOutQuad(t);

        // Update the height of the bars based on the easing function
        int posX = 0;
        for (int i = 0; i < n; i++) {
            float targetHeight = targetHeights[i];
            float currentHeight = minHeight + (targetHeight - minHeight) * easedT;
            bars[i].setSize(sf::Vector2f(barWidth-2, currentHeight));
            bars[i].setPosition(posX, windowHeight - currentHeight);
            posX += barWidth; 
        }

        // Clear the window
        window.clear();

        // Draw the bars
        for (int i = 0; i < n; i++) {
            window.draw(bars[i]);
        }

        // Display the contents of the window
        window.display();

        if (elapsedTime >= animationDuration)
            break; // Exit the loop once the animation is complete
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Animation");


    drawBars(window, numberOfBars);

    // Keep the window open until it is manually closed
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}

