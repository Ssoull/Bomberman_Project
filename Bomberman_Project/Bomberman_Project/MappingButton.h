#pragma once

#include "Button.h"
#include "ActionButton.h"

#include <functional>

class MappingButton
{
protected:
	static ActionButton m_actionButton;

	std::map< Button*, std::function< ScreenToDisplay(ActionButton&) > > m_mapOfButton;

public:
	MappingButton();

	void addButtonInMapping(Button* button, std::function< ScreenToDisplay(ActionButton&) > action);

	virtual ~MappingButton();
};

