#include <iostream>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <sstream>
#include <string>
#include <map>


//creation d'une classe piece
class piece{
        public:
        std::vector<std::vector<int>> forme_;
        sf::Color couleur_;
        std::vector<int> centre {0,0};

        piece(std::vector<std::vector<int>> forme, sf::Color couleur) : forme_{forme}, couleur_{couleur} {};

        void affiche(sf::RenderWindow& window){
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(forme_[j][i] == 1){
                        sf::RectangleShape carre_ij({50.f, 50.f});
                        carre_ij.move({static_cast<float>(200 +50*i),static_cast<float>(50*j)});
                        carre_ij.setFillColor(couleur_);
                        carre_ij.setOutlineThickness(-5.f);
                        carre_ij.setOutlineColor(sf::Color(couleur_.r + 50., couleur_.g + 50.,couleur_.b + 50));
                        window.draw(carre_ij);
                    }
                };
            };
        };

    };

class Board{

public:
    int colonnes_;
    int lignes_;
    std::vector<std::vector<int>> board_;  
    std::vector<std::vector<sf::Color>> couleurs_;

    Board(int colonnes, int lignes)
        : colonnes_{colonnes}, lignes_{lignes}, board_(lignes, std::vector<int>(colonnes, 0)), couleurs_(lignes, std::vector<sf::Color>(colonnes,sf::Color::Black)) {}
    

    

    void affiche(sf::RenderWindow& window){
        for(int i=0; i<lignes_; i++){
            for(int j=0; j<colonnes_; j++){
                if(board_[i][j] == 1){
                    sf::RectangleShape carre_ij({50.f, 50.f});
                    carre_ij.move({static_cast<float>(500-50*j),static_cast<float>(800-50*i)});
                    carre_ij.setFillColor(couleurs_[i][j]);
                    carre_ij.setOutlineThickness(-5.f);
                    carre_ij.setOutlineColor(sf::Color(couleurs_[i][j].r + 50., couleurs_[i][j].g + 50.,couleurs_[i][j].b + 50));                        window.draw(carre_ij);
                }
            };
        };
    };

    void drop_ligne(int ligne){
        for(int i=ligne; i < lignes_ -1; i++){
            board_[i] = board_[i+1];

        };
    };

    void ajout(piece& tetromino){
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(tetromino.forme_[i][j] = 1)
                    board_[i + 14][j+4] = 1;
            }
        };
    }


    


};


// définition d'une fonction qui vérifiera à chaque itération si le mouvement engendre une collision
bool collision(piece& tetromino, Board& board){
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(tetromino.forme_[i][j] == 1){
                if((tetromino.centre[0] + i > 16) ||(board.board_[tetromino.centre[0] + i][tetromino.centre[1] + j] == 1) || (tetromino.centre[1] +j > 5) || (tetromino.centre[1] + j < -5)){
                    return(1);
                };
            };
        };
    };
    return(0); 
};



//formes:
const std::vector<std::vector<int>> forme_z = {{1,1,0},{0,1,1},{0,0,0}};
const std::vector<std::vector<int>> forme_s = {{0,1,1},{1,1,0},{0,0,0}};
const std::vector<std::vector<int>> forme_o = {{1,1,0},{1,1,0},{0,0,0}};
const std::vector<std::vector<int>> forme_l = {{0,1,0},{0,1,0},{0,1,1}};
const std::vector<std::vector<int>> forme_j = {{0,1,0},{0,1,0},{1,1,0}};
const std::vector<std::vector<int>> forme_i = {{0,1,0},{0,1,0},{0,1,0}};
const std::vector<std::vector<int>> forme_t = {{1,1,0},{0,1,1},{0,0,0}};

//couleur des pieces:
const sf::Color bleu = sf::Color(0,0,200);
const sf::Color rouge = sf::Color(200,0,0);
const sf::Color green = sf::Color(0,200,0);
const sf::Color orange = sf::Color(200,100,0);
const sf::Color jaune = sf::Color(200,200,0);
const sf::Color violet = sf::Color(100,20,200);
const sf::Color rose = sf::Color(200,10,50);


std::map<std::string, piece> pieces{{"z",piece(forme_z, rose)},
                                    {"s",piece(forme_s, rose)},
                                    {"o",piece(forme_o, rose)},
                                    {"l",piece(forme_l, rose)},
                                    {"j",piece(forme_j, rose)},
                                    {"i",piece(forme_i, rose)},
                                    {"t",piece(forme_t, rose)},};

piece tetro = pieces["z"];

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



   

    sf::Clock clock;
    //board de jeu
    Board plateau = Board(10,16);


    bool rotate;
    int dx;
    int dy;

    //ici créer une fonction rotate et une fonction move
    //CODER LA FONCTION MOVE    
    void move(int dx,int dy, Board& board, piece& tetromino){
        return 0
    }


    // j'ai essayé de tester le code en ajoutant juste une pièce z pour commencer: 
    // Ca marchait au début puis j'ai ajouté ddes procédures dans la classe pièce et ca ne veut plus compiler
    // J'ai un gros pavé d'erreur à la compilation que meme chat gpt n'arrive pas à résoudre
    plateau.ajout(tetro);


    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
            dx = 1;
            dy=0;
            if(e.type == sf::Event::KeyPressed){
                if(e.key.code==sf::Keyboard::Up) rotate=true;
                else if (e.key.code==sf::Keyboard::Left) dy=-1;
                else if (e.key.code==sf::Keyboard::Right) dy=1;

            };

            move(dx,dy, plateau, tetro);
            if(collision(tetro, plateau)){
                move(-dx,-dy, plateau, tetro)
            };
            // Je voulais aussi faire une fonction qui différencie si la collision à lieu avec une autre pice ou avec un mur pour savoir quand lancer une autre piece
        };
        

    // le jeu ici:
    sf::Time frame = sf::seconds(1.f);
    //actions à effectuer à chaque frame
    if(sf::operator>(clock.getElapsedTime() , frame)){
        clock.restart();
        window.clear(sf::Color::Black);
        plateau.affiche(window);
    };
    


    // Afficher le contenu
    
    window.display();
    }




    }
    
