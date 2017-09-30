#include "Controller.h"



/***********************************\
*  Constructor of the class         *
* controller.                       *
\***********************************/
Controller::Controller(Model* model, View* view) : m_model(model), m_view(view)
{

}



/***********************************\
*  Used the functions of the model  *
* according to the events from      *
* the player.                       *
\***********************************/
void Controller::treatEvents()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_view->checkMouseClickInWindow())
	{
		m_view->checkButtonStateOnMouseClick();
	}
}


/***********************************\
*  Destructor of the controller.    *
\***********************************/
Controller::~Controller()
{

}
