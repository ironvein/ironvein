// local
#include "ui/window.h"
#include "util/output.h"

namespace IronVein
{
	namespace UI
	{
		Window::Window()
		{
			// Constructor
		}

		void Window::init(u16 width, u16 height, bool enabled)
		{
			Util::output("Initialising Window");

			this->_internal.create(sf::VideoMode(width, height), "IronVein", sf::Style::Default);
			this->setEnabled(enabled);
		}

		void Window::setEnabled(bool enabled)
		{
			this->_internal.setVisible(enabled);
		}

		void Window::display()
		{
			this->_internal.display();
		}
	}
}
