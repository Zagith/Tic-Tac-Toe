#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player {
public:
    Player(string playerSymbol);

    void getPlayerInput(string &input);
    void increaseScore();
    string getPlayerSymbol() const;
    int getScore() const;

private:
    string playerSymbol;
    int score;
};

#endif //PLAYER_H
