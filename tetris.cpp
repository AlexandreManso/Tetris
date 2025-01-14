#include <iostream>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(800,600), "Tetris");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


            sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("Tetris.wav")) {
        std::cerr << "Failed to load .wav file!" << std::endl;
        return -1;
    }

        // Create a sound object and set its buffer
        sf::Sound sound;
        sound.setBuffer(buffer);

        // Play the sound
        sound.play();
        // Effacer l'écran
        window.clear(sf::Color::Black);
        // Afficher le contenu
        window.display();
    }
    


}