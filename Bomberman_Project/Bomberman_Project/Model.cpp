#include "Model.h"


/***********************************\
*  Constructor of the class model.  *
\***********************************/
Model::Model() : m_quitGame(false)
{
}



void Model::quitTheGame()
{
	m_quitGame = true;
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

}
