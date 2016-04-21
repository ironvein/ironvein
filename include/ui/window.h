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
			void init(u16 width, u16 height, bool enabled = true);
			void setEnabled(bool enabled = true);
			std::vector<sf::Event> getEvents();
			void display();
			void close();
		};
	}
}

#endif
