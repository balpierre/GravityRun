#include "../inc/graphic/graphic.hpp"
#include "Player/Player.hpp"
#include "graphic/map.hpp"

int game_loop2(Character ch, uint hs);

int main(void)
{
    Character ch = Game_Loop();
    if (ch == undifined)
        exit(0);
    uint hScore = highscore_read();
    game_loop2(ch, hScore);
}

int game_loop2(Character ch, uint hs)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML window");
    window.setFramerateLimit(240);
    Map m;
    Player ply({450, 10 * 50}, ch);
    sf::Font font;
    font.loadFromFile("assets/Sonic Barrier.ttf");
    sf::Text txt(std::to_string(0), font, 33);
    sf::Text hs_txt(std::string( "Highscore: " + std::to_string(hs)), font, 33);
    hs_txt.setPosition({1700, 25});
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
        window.draw(hs_txt);
        if (!ply.update(m.getMap(ply.get_pos()), m.getDistance()))
        {
            if (m.getScore() > ((int)hs)) {
                highscore_write(m.getScore());
            }
            exit(0);
        }
        window.draw(ply.get_sprite());
        window.display();
    }
    return (0);
}