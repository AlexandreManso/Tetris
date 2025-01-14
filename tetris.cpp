#include <iostream>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>

int main() {

    sf::RenderWindow window(sf::VideoMode(500,800), "Tetris");
    window.setVerticalSyncEnabled(true);


    sf::Music music;
    if (!music.openFromFile("Tetris.ogg")) {
        std::cerr << "Failed to load .ogg file!" << std::endl;
        return -1;
        }

    // Play the music
    music.setVolume(100.);
    music.play();

    int score = 0;


    // sf::Font font;
    // if (!font.loadFromFile("/home/alex/info/cpp-tetris/Tetris/chilispepper.ttf")) {
    //     std::cerr << "Error loading font!" << std::endl;
    //     return -1;
    // }

    sf::RectangleShape rectangle({100.f,100.f});

    //pièce z


// define the points
convex.setPoint(0, {0.f, 0.f});
convex.setPoint(1, {150.f, 10.f});
convex.setPoint(2, {120.f, 90.f});
convex.setPoint(3, {30.f, 100.f});
convex.setPoint(4, {0.f, 50.f});

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    // le jeu ici:
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
    // left key is pressed: move our character
    // character.move({-1.f, 0.f});
    }



        // Effacer l'écran
        window.clear(sf::Color::Black);
       
        // //affichage du score
        // std::stringstream ss;
        // ss << "votre score est de" << score;
        // std::string score_str = ss.str();
        // sf::Text text;
        // text.setString(score_str);
        // text.setFillColor(sf::Color::White);
        // text.setFont(font);
        // text.setPosition(100,100);
        // window.draw(text);



        // Afficher le contenu
        window.draw(rectangle);
        window.display();
    }
    


}