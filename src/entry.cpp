#include "../inc/graphic/graphic.hpp"
#include "Player/Player.hpp"
#include "graphic/map.hpp"

int game_loop2(Character ch);

int main(void)
{
    Character ch = Game_Loop();
    if (ch == undifined)
        exit(0);
    game_loop2(ch);
}

int game_loop2(Character ch)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML window");
    window.setFramerateLimit(240);
    Map m;
    Player ply({450, 16 * 50}, ch);
    sf::Font font;
    font.loadFromFile("assets/Sonic Barrier.ttf");
    sf::Text txt(std::to_string(0), font, 33);
    txt.setPosition({960 , 25});

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
        window.clear();
        m.scrollMap();
        m.draw(window);
        txt.setString(std::to_string(m.getScore()));
        window.draw(txt);
        if (!ply.update(m.getMap(ply.get_pos()), m.getDistance()))
        {
            //LE PLAYER EST MORT
            exit(0);
        }
        window.draw(ply.get_sprite());
        window.display();
    }
    return (0);
}