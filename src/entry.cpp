#include "../inc/graphic/map.hpp"

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML window");
    window.setFramerateLimit(90);
    Map m;

    m.initMap("block-map");
    m.setSize(50);
    m.setSpeed(1);

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        std::cout << m.getPos() << std::endl;
        window.clear();
        m.scrollMap();
        m.draw(window);
        window.display();
    }
    return (0);
}