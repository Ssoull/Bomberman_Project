#include "Model.h"


/***********************************\
*  Constructor of the class model.  *
\***********************************/
Model::Model() : m_quitGame(false)
{
}



// Getter
bool Model::getQuitGame() const
{
	return m_quitGame;
}



/***********************************\
*  Destructor of the model.         *
\***********************************/
Model::~Model()
{
	std::cout << "Here i'm in the model destructor." << std::endl;
}
