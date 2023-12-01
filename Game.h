#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "Player.h"

using namespace std;

class Game {
public:
    Game();

    void drawGrid();

    void askPlayerSetTile(bool xTurn);

    void setPlayerScore(bool xTurn);

    void printPlayersScore() const;

    void resetGame();
    bool isBoardFull() const;

    bool checkWin(bool xTurn, string &winner) const;

private:
    static const int ROWS = 3;
    static const int COLS = 3;
    vector<Player> players;
    string gridCells[ROWS][COLS];

    void initializeGrid() {
        auto index = 1;
        for (auto i = 0; i < ROWS; i++) {
            for (auto j = 0; j < COLS; j++) {
                gridCells[i][j] = to_string(index);
                index++;
            }
        }
    }

    void initializePlayers() {
        players.push_back(*new Player("X"));
        players.push_back(*new Player("O"));
    }

    bool setTile(int input, string playerSymbol) {
        for (auto i = 0; i < ROWS; i++) {
            for (auto j = 0; j < COLS; j++) {
                if (gridCells[i][j] == to_string(input)) {
                    gridCells[i][j] = playerSymbol;
                    return true;
                }
            }
        }
        return false;
    }

    bool checkPlayerInput(string input) {
        bool result = true;
        for (char c: input) {
            if (!isdigit(c)) {
                result = false;
                break;
            }
        }
        return result;
    }
};

#endif //GAME_H
