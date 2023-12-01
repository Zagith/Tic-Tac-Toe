#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(string playerSymbol) {
    this->playerSymbol = playerSymbol;
    score = 0;
}

string Player::getPlayerSymbol() const
{
    return playerSymbol;
}

int Player::getScore() const
{
    return score;
}

void Player::increaseScore()
{
    score += 1;
}

void Player::getPlayerInput(string &input) {

    cout << "Write a displayed number to place your tile:\t";
    cin >> input;
    cout << endl;
}