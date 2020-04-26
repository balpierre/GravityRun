#include "../inc/graphic/graphic.hpp"
#include "Player/Player.hpp"

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML window");
    window.setFramerateLimit(240);
    Map m;
    Player ply({450, 16 * 50});
    sf::RectangleShape rect({20, 20});
    sf::Image img;
    rect.setFillColor(sf::Color::White);
    img.loadFromFile("assets/momo.png");
    sf::Texture text;
    text.loadFromImage(img);
    sf::Sprite sprite;
    sprite.setTexture(text);
    sprite.setPosition(0, 490);

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
        ply.update(m.getMap(ply.get_pos()), m.getDistance());
        rect.setPosition(ply.get_pos());
        window.draw(sprite);
        window.draw(rect);
        window.display();
    }
    return (0);
}