
// This file is complete, and should not be modified!

#pragma once

class Game
{

public:

	Game() { }
	Game(const Game&) = delete;
	virtual ~Game() { }

	Game& operator=(const Game&) = delete;


	// Methods to be implemented by derived class

	virtual bool IsGameOver() const = 0;

	virtual void TakeTurn() = 0;

	virtual void Display() const = 0;

};

