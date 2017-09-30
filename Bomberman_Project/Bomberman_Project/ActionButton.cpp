#include "ActionButton.h"



ActionButton::ActionButton()
{
}



ScreenToDisplay ActionButton::launchGame()
{
	return Game;
}

ScreenToDisplay ActionButton::optionView()
{
	return Option;
}

ScreenToDisplay ActionButton::quitGame()
{
	return Quit;
}



ActionButton::~ActionButton()
{
}
