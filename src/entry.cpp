#include "../inc/graphic/graphic.hpp"

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML window");
    Map m;

    m.initMap("block-map");
    m.setSize(50);
    m.setSpeed(1000);

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        m.scrollMap();
        m.draw(window);
        window.display();
        window.setFramerateLimit(60);
    }

    return (0);
}