#ifndef IRONVEIN_UI_WIDGETS_WIDGET
#define IRONVEIN_UI_WIDGETS_WIDGET

// local
#include "ui/window.h"

namespace IronVein
{
	namespace UI
	{
		/* Forward declaration of Interface*/
		class Interface;

		namespace Widgets
		{
			/* An abstract class acting as a blueprint for all UI widgets */
			class Widget
			{
			public:
				Widget();
				virtual ~Widget();
				virtual void init(Interface& interface) = 0;

				virtual void passEvent(sf::Event event) = 0;

				virtual void tick(Interface& interface, bool has_focus = false) = 0;
				virtual void render(Interface& interface, Window& window, bool has_focus = false) = 0;
			};
		}
	}
}

#endif
