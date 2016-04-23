#ifndef IRONVEIN_UI_WIDGETS_CHATWIDGET
#define IRONVEIN_UI_WIDGETS_CHATWIDGET

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
			class ChatWidget : public Widget
			{
				std::string _input_text = "";
				glm::vec2 _pos = glm::vec2(256, 256);
				glm::vec2 _size = glm::vec2(256, 256);
				bool _drag = false;
				glm::vec2 _drag_pos;

			public:
				ChatWidget();
				virtual ~ChatWidget();
				void init(Interface& interface);

				void passEvent(sf::Event event, Interface& interface);

				void tick(Interface& interface, bool has_focus = false);
				void render(Interface& interface, Window& window, bool has_focus = false);
			};
		}
	}
}

#endif
