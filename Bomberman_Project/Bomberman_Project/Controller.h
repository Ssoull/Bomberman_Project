#pragma once

#include "Model.h" // Allows the use of Model class.
#include "View.h" // Allows the use of View class.

/***********************************************\
*  This class represents the part of MVC model  *
* which react to the actions of the player.     *
\***********************************************/
class Controller
{
private:
	Model* m_model;
	View* m_view;

public:
	Controller(Model* model, View* view); // Constructor
	
	bool treatEvents(); // Treat events from the player.

	~Controller(); // Destructor

};

