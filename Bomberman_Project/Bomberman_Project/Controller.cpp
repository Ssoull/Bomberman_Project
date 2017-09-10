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
bool Controller::treatEvents()
{
	return true;
}



/***********************************\
*  Destructor of the controller.    *
\***********************************/
Controller::~Controller()
{
	std::cout << "Here i'm in the controller destructor." << std::endl;
}
