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
			this->_internal.setVerticalSyncEnabled(true);
			this->_internal.setFramerateLimit(30);
			this->setEnabled(enabled);
		}

		void Window::setEnabled(bool enabled)
		{
			Util::output("Enabling Window instance");
			this->_internal.setVisible(enabled);
		}

		std::vector<sf::Event> Window::getEvents()
		{
			std::vector<sf::Event> event_vector;

			sf::Event event;
			while (this->_internal.pollEvent(event))
			{
				event_vector.push_back(event);
			}

			return event_vector;
		}

		void Window::display()
		{
			this->_internal.display();
		}

		void Window::close()
		{
			Util::output("Closing Window instance");
			this->_internal.close();
		}
	}
}
