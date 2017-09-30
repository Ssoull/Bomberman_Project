#include "MappingButton.h"

ActionButton MappingButton::m_actionButton;

MappingButton::MappingButton()
{

}

void MappingButton::addButtonInMapping(Button* button, std::function< ScreenToDisplay(ActionButton&) > action)
{
	m_mapOfButton[button] = action;
}

MappingButton::~MappingButton()
{
	if (!m_mapOfButton.empty())
	{
		for (std::map< Button*, std::function< ScreenToDisplay(ActionButton&) > >::iterator it = m_mapOfButton.begin(); it != m_mapOfButton.end(); ++it) {
			delete it->first;
		}

		m_mapOfButton.clear();
	}
}
