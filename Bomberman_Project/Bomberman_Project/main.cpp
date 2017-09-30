#include "Controller.h" // Allows the use of Controller class.
#include "Model.h" // Allows the use of Model class.
#include "View.h" // Allows the use of View class.

#include <ostream>


int main()
{

	Model* m_model = new Model(); // Declaration and initialization of the model in the memory.

	View* m_view = new View(m_model, WIDTH_WINDOW, HEIGHT_WINDOW); // Declaration and initialization of the view in the memory.

	Controller* m_controller; // Declaration of the controller.

	if (m_view != nullptr && m_model != nullptr) // If m_view and m_model are initialized.
	{
		m_controller = new Controller(m_model, m_view); // Initialization of the controller in the memory.

		while (!m_model->getQuitGame() && !m_view->windowClosed()) // While the game isn't over or the window closed not closed.
		{
			m_controller->treatEvents(); // Events are treated.
			m_view->displayGame(); // The game is displayed.
		}
	}


	if (m_controller != nullptr) // If m_controller is initialized.
	{
		delete m_controller; // Deallocates a block of memory.
	}

	if (m_view != nullptr)  // If m_view is initialized.
	{
		delete m_view; // Deallocates a block of memory.
	}
	
	if (m_model != nullptr) // If m_model is initialized.
	{
		delete m_model; // Deallocates a block of memory.
	}

	return 0;
}

