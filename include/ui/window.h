#ifndef IRONVEIN_UI_WINDOW
#define IRONVEIN_UI_WINDOW

// local
#include "util/type.h"

// library
#include "SFML/Graphics.hpp"

// standard
#include "vector"

namespace IronVein
{
	namespace UI
	{
		class Window
		{
			sf::RenderWindow _internal;

		public:
			Window();
			void init(u16 width, u16 height);
			void close();

			void setEnabled(bool enabled = true);
			bool isOpen();

			std::vector<sf::Event> getEvents();
			sf::RenderWindow& getInternal();

			void clear(sf::Color colour);
			void display();
		};
	}
}

#endif
