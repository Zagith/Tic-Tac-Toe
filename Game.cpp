#include <iostream>
#include "Game.h"

using namespace std;

Game::Game() {
    initializePlayers();
    initializeGrid();
}

void Game::drawGrid() {
    for (auto i = 0; i < ROWS; i++) {
        for (auto j = 0; j < COLS; j++) {
            cout << gridCells[i][j];

            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "- - - - -" << endl;
        }
    }

    cout << endl;
}

void Game::askPlayerSetTile(bool xTurn) {
    auto player = xTurn ? players[0] : players[1];
    auto keepAsking = true;

    cout << "It is " << player.getPlayerSymbol() << "'s turn" << endl;
    while (keepAsking) {

        string input;
        player.getPlayerInput(input);

        if (checkPlayerInput(input)) {
            int playerInput = std::stoi(input);
            if (playerInput < 1 || playerInput > 9) {
                cout << "You insert wrong inputs, should be a number between 1 and 9." << endl;
            } else if (!setTile(playerInput, player.getPlayerSymbol())) {
                cout << "Cell Occupied! Retry" << endl;
            } else
                keepAsking = false;
        } else {
            cout << "You insert wrong inputs, should be a number between 1 and 9." << endl;
        }
    }
}

void Game::setPlayerScore(bool xTurn) {
    if (xTurn) {
        players[0].increaseScore();
        return;
    }
    players[1].increaseScore();
}

void Game::printPlayersScore() const
{
    cout << "Players Score:"<<endl;
    cout << "\tX: "<<players[0].getScore()<<endl;
    cout << "\tO: "<<players[1].getScore()<<endl;
}

void Game::resetGame()
{
    initializeGrid();
}
bool Game::isBoardFull() const {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (gridCells[i][j] != "X" && gridCells[i][j] != "O")
                return false;

        }
    }

    cout << "A Cat's game! no one has won the game." << endl;
    return true;
}

bool Game::checkWin(bool xTurn, string &winner) const {

    auto player = xTurn ? players[0].getPlayerSymbol() : players[1].getPlayerSymbol();

    for (int i = 0; i < ROWS; i++) {
        if (gridCells[i][0] == player && gridCells[i][1] == player && gridCells[i][2] == player ||
            gridCells[0][i] == player && gridCells[1][i] == player && gridCells[2][i] == player) {
            cout << "Congratulation! Player: " << player << " has won the game!" << endl;
            winner = player;
            return true;
        }
    }

    if ((gridCells[0][0] == player && gridCells[1][1] == player && gridCells[2][2] == player) ||
        (gridCells[0][2] == player && gridCells[1][1] == player && gridCells[2][0] == player)) {
        cout << "Congratulation! Player: " << player << " has won the game!" << endl;
        winner = player;
        return true;
    }

    return false;
}