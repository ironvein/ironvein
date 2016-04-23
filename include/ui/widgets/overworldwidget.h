#ifndef IRONVEIN_UI_WIDGETS_OVERWORLDWIDGET
#define IRONVEIN_UI_WIDGETS_OVERWORLDWIDGET

// local
#include "ui/widgets/widget.h"

// library
#include "glm/glm.hpp"

// standard
#include "string"

namespace IronVein
{
	namespace UI
	{
		namespace Widgets
		{
			class OverworldWidget : public Widget
			{
				glm::vec2 _position = glm::vec2(16, 16);
				bool _visible = true;

			public:
				OverworldWidget();
				virtual ~OverworldWidget();
				void init(Interface& interface);

				void passEvent(sf::Event event, Interface& interface);

				void tick(Interface& interface, bool has_focus = false);
				void render(Interface& interface, Window& window, bool has_focus = false);
			};
		}
	}
}

#endif
