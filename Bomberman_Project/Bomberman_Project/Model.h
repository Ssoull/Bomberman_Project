#pragma once

#include <iostream> // Allows the use of input and output in the console.

/***********************************************\
*  This class represents the part of MVC model  *
* which contains all functions modifying        *
* the values.                                   *
\***********************************************/
class Model
{
private:
	bool m_quitGame; // Represents if the game is left.

public:
	Model(); // Default constructor

	bool getQuitGame() const;

	~Model(); // Destructor
};

