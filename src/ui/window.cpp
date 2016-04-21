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

		void Window::init(u16 width, u16 height)
		{
			Util::output("Initialising Window");

			this->_internal.create(sf::VideoMode(width, height), "IronVein", sf::Style::Default);
			this->_internal.setVerticalSyncEnabled(true);
			this->_internal.setFramerateLimit(30);
			this->_internal.setVisible(false);
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

		bool Window::isOpen()
		{
			return this->_internal.isOpen();
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

		void Window::clear(sf::Color colour)
		{
			this->_internal.clear(colour);
		}

		sf::RenderWindow& Window::getInternal()
		{
			return this->_internal;
		}
	}
}
