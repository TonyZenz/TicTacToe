#pragma once
#include "game.h"
#include <iostream>

class TicTacToe : public Game
{
private:
	char board[9];
	int currentPlayer;
	int turnCounter;

    // Checks for three in a row
	bool WinnerCheck() const
	{
        // Rows
        if (board[0] != ' ' && board[0] == board[1] && board[1] == board[2]) return true;
        if (board[3] != ' ' && board[3] == board[4] && board[4] == board[5]) return true;
        if (board[6] != ' ' && board[6] == board[7] && board[7] == board[8]) return true;

        // Columns
        if (board[0] != ' ' && board[0] == board[3] && board[3] == board[6]) return true;
        if (board[1] != ' ' && board[1] == board[4] && board[4] == board[7]) return true;
        if (board[2] != ' ' && board[2] == board[5] && board[5] == board[8]) return true;

        // Diagonals
        if (board[0] != ' ' && board[0] == board[4] && board[4] == board[8]) return true;
        if (board[2] != ' ' && board[2] == board[4] && board[4] == board[6]) return true;

        return false;
	}

    // Checks if the board is full
    bool IsBoardFull() const
    {
        return turnCounter >= 9;
    }

public:

    // Constructor
    TicTacToe()
        : currentPlayer(0), turnCounter(0)
    {
        for (int i = 0; i < 9; i++)
            board[i] = ' ';
    }

    // Destructor
    ~TicTacToe() {};

    // Check for end of game
    bool IsGameOver() const
    {
        return WinnerCheck() || IsBoardFull();
    }

    // Display

    void Display() const
    {
        std::cout << "\nCurrent board:\n\n";

        for (int i = 0; i < 9; i++)
        {
            std::cout << " " << board[i] << " ";

            if (i % 3 != 2)
                std::cout << "|";

            if (i % 3 == 2 && i < 8)
                std::cout << "\n-----------\n";
        }

        std::cout << "\n\nCurrent Player: " << currentPlayer + 1 << "\n\n";
    }

    // Take turn

    void TakeTurn()
    {
        int pos = 0;
        bool move = false;

        // Input prompting and validation
        while (!move)
        {
            std::cout << "Player " << (currentPlayer == 0 ? 'X' : 'O') << ", enter a position (1-9): ";
            std::cin >> pos;

            if (pos >= 1 && pos <= 9 && board[pos - 1] == ' ')
            {
                move = true;
            }
            else
            {
              std::cout << "Invalid move. ";
              if (pos < 1 || pos > 9) std::cout << "Position must be between 1 and 9. ";
              else std::cout << "That spot is already taken. \n";
            }
        }

        // Places marker
        board[pos - 1] = (currentPlayer == 0) ? 'X' : '0';
        turnCounter++;

        // Switch player
        currentPlayer = (currentPlayer == 0) ? 1 : 0;
    }
};