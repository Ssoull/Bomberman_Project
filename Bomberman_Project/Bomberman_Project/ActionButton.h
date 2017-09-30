#pragma once


enum ScreenToDisplay { Menu, Game, Option, Quit };

class ActionButton
{
public:
	ActionButton();

	ScreenToDisplay launchGame();
	ScreenToDisplay optionView();
	ScreenToDisplay quitGame();

	~ActionButton();
};

