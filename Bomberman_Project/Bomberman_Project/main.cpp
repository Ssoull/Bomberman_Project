#include "Controller.h" // Allows the use of Controller class.
#include "Model.h" // Allows the use of Model class.
#include "View.h" // Allows the use of View class.


int main()
{
	View* m_view = new View(400, 400); // Declaration and initialization of the view in the memory.
	Model* m_model = new Model(); // Declaration and initialization of the model in the memory.
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
		std::cout << "Before delete m_controller." << std::endl;
		delete m_controller; // Deallocates a block of memory.
	}

	if (m_model != nullptr) // If m_model is initialized.
	{
		std::cout << "Before delete m_model." << std::endl;
		delete m_model; // Deallocates a block of memory.
	}

	if (m_view != nullptr)  // If m_view is initialized.
	{
		std::cout << "Before delete m_view." << std::endl;
		delete m_view; // Deallocates a block of memory.
	}
	
	return 0;
}