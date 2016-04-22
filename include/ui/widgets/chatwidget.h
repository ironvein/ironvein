#ifndef IRONVEIN_UI_WIDGETS_CHATWIDGET
#define IRONVEIN_UI_WIDGETS_CHATWIDGET

// local
#include "ui/widgets/widget.h"

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

			public:
				ChatWidget();
				virtual ~ChatWidget();
				void init(Interface& interface);

				void passEvent(sf::Event event);

				void tick(Interface& interface, bool has_focus = false);
				void render(Interface& interface, Window& window, bool has_focus = false);
			};
		}
	}
}

#endif
