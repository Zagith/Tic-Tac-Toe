#include <iostream>
#include <string>
#include <memory>
#include "Game.h"

using namespace std;

void runGameLoop(unique_ptr<Game> &game);

int main() {
    auto exit = false;
    auto game = make_unique<Game>();
    while (!exit) {
        runGameLoop(game);
        string input;
        cout << "Do you want continue with a new game? Y / N" << endl;
        cin >> input;

        if (input != "Y" && input != "y") {
            exit = true;
        }
        game->resetGame();
    }
    return 0;
}

void runGameLoop(unique_ptr<Game> &game) {
    srand(time(nullptr));

    auto rnd = rand() % 2;
    auto xTurn = rnd == 0;

    string winner = "";
    game->drawGrid();

    while (winner == "") {
        game->askPlayerSetTile(xTurn);

        game->drawGrid();

        game->checkWin(xTurn, winner);

        if (winner == "") {
            if (game->isBoardFull()) {
                winner = "C";  //Cat's game... no winner!
            }
            else
            {
                xTurn = !xTurn;
            }
        }
        else
        {
            game->setPlayerScore(xTurn);
            game->printPlayersScore();
        }
    }

    cout << "Game Completed!" << endl;
}