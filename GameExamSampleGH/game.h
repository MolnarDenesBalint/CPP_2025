//
// Created by denes on 2025. 10. 21..
//

#ifndef GAMEEXAMSAMPLEGH_GAME_H
#define GAMEEXAMSAMPLEGH_GAME_H

#include <string>

using namespace std;
class Game {
public:
// Constructors
    Game();
    Game(const std::string &title, double price);
    Game(const Game &other);
    Game(Game &&other);
// Assignment operators
    Game& operator=(const Game &other);
    Game& operator=(Game &&other);
// Getter methods
    std::string getTitle() const;
    double getPrice() const;
// Equality operator overloading
    bool operator==(const Game &other);
// Inserter operator
    friend std::ostream& operator<<(std::ostream &os, const Game &game);
// Extractor operator
    friend std::istream& operator>>(std::istream &is, Game &game);
private:
    std::string title;
    double price;
};
#endif //GAMEEXAMSAMPLEGH_GAME_H
