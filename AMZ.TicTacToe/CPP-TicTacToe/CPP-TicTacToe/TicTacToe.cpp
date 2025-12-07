#include "TicTacToe.h"
#include <iostream>

// Constructor
TicTacToe::TicTacToe()
{
    for (int i = 0; i < 9; i++)
        m_board[i] = ' ';
    m_currentPlayer = 0;
    m_turnCounter = 0;
}

// Checks for three in a row
bool TicTacToe::WinnerCheck() const
{
    // Rows
    if (m_board[0] != ' ' && m_board[0] == m_board[1] && m_board[1] == m_board[2]) return true;
    if (m_board[3] != ' ' && m_board[3] == m_board[4] && m_board[4] == m_board[5]) return true;
    if (m_board[6] != ' ' && m_board[6] == m_board[7] && m_board[7] == m_board[8]) return true;

    // Columns
    if (m_board[0] != ' ' && m_board[0] == m_board[3] && m_board[3] == m_board[6]) return true;
    if (m_board[1] != ' ' && m_board[1] == m_board[4] && m_board[4] == m_board[7]) return true;
    if (m_board[2] != ' ' && m_board[2] == m_board[5] && m_board[5] == m_board[8]) return true;

    // Diagonals
    if (m_board[0] != ' ' && m_board[0] == m_board[4] && m_board[4] == m_board[8]) return true;
    if (m_board[2] != ' ' && m_board[2] == m_board[4] && m_board[4] == m_board[6]) return true;

    return false;
}

// Display
void TicTacToe::Display() const
{
    std::cout << "\nCurrent board:\n\n";

    for (int i = 0; i < 9; i++)
    {
        std::cout << " " << m_board[i] << " ";

        if (i % 3 != 2)
            std::cout << "|";

        if (i % 3 == 2 && i < 8)
            std::cout << "\n-----------\n";
    }
    if (WinnerCheck()) { std::cout << "\n\nPlayer " << m_currentPlayer << " wins!"; };
    if (IsBoardFull()) { std::cout << "\n\nDraw!"; };
    std::cout << "\n\nCurrent Player: " << m_currentPlayer + 1 << "\n\n";
}

// Prompts input, validates, places mark, increments turn, and switches current player
void TicTacToe::TakeTurn()
{
    int pos = 0;
    bool move = false;

    // Input prompting and validation
    while (!move)
    {
        std::cout << "Player " << (m_currentPlayer == 0 ? 'X' : 'O') << ", enter a position (1-9): ";
        std::cin >> pos;

        if (pos >= 1 && pos <= 9 && m_board[pos - 1] == ' ')
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
    m_board[pos - 1] = (m_currentPlayer == 0) ? 'X' : '0';
    m_turnCounter++;

    // Switch player
    m_currentPlayer = (m_currentPlayer == 0) ? 1 : 0;
}