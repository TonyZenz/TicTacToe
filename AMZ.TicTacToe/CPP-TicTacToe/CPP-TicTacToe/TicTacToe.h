#pragma once
#include "game.h"

class TicTacToe : public Game
{
private:

	char m_board[9];
	int m_currentPlayer;
	int m_turnCounter;

public:

    // Constructor
    TicTacToe();

    // Destructor
    ~TicTacToe() {};

    // Checks for three in a row
    bool WinnerCheck() const;

    // Checks if the board is full
    bool IsBoardFull() const { return m_turnCounter >= 9; }

    // Check for end of game
    bool IsGameOver() const {return WinnerCheck() || IsBoardFull();}
    
    // Display
    void Display() const;
    
    // Take turn
    void TakeTurn();
};