#include "../inc/graphic/graphic.hpp"
#include "Player/Player.hpp"

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML window");
    window.setFramerateLimit(180);
    Map m;
    Player ply({450, 16 * 50});
    sf::RectangleShape rect({20, 20});
    rect.setFillColor(sf::Color::White);

    m.initMap("block-map");
    m.setSize(50);
    m.setSpeed(1);
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Space)
                    ply.swap_gravity();
        }
        std::cout << m.getPos() << std::endl;
        window.clear();
        m.scrollMap();
        m.draw(window);
        ply.update(m.getMap(), m.getDistance());
        rect.setPosition(ply.get_pos());
        window.draw(rect);
        window.display();
    }
    return (0);
}