// local
#include "ui/widgets/chatwidget.h"
#include "util/output.h"
#include "ui/interface.h"

namespace IronVein
{
	namespace UI
	{
		namespace Widgets
		{
			ChatWidget::ChatWidget()
			{
				// Constructor
			}

			ChatWidget::~ChatWidget()
			{
				// Destructor
			}

			void ChatWidget::init(Interface& interface)
			{
				Util::output("Initialising ChatWidget instance");
			}

			void ChatWidget::passEvent(sf::Event event)
			{
				switch (event.type)
				{
				case sf::Event::TextEntered:
					Util::output(std::string("ChatWindow got passed '") + static_cast<char>(event.text.unicode) + "'");

					if (static_cast<char>(event.text.unicode) == '\b')
					{
						if (this->_input_text.size() > 0)
							this->_input_text.pop_back();
					}
					else
						this->_input_text += static_cast<char>(event.text.unicode);
					break;

				default:
					break;
				}
			}

			void ChatWidget::tick(Interface& interface, bool has_focus)
			{
				// Tick
			}

			void ChatWidget::render(Interface& interface, Window& window, bool has_focus)
			{
				sf::RectangleShape chat_window_border;
				chat_window_border.setPosition(sf::Vector2f(16, 16));
				chat_window_border.setSize(sf::Vector2f(256, 256));
				chat_window_border.setFillColor(sf::Color(0, 200, 0, 100));

				sf::Text chat_text;
				chat_text.setString(this->_input_text);
				chat_text.setFont(interface.getDefaultFont());
				chat_text.setPosition(sf::Vector2f(24, 24));
				chat_text.setCharacterSize(12);
				chat_text.setColor(sf::Color::White);

				window.getInternal().draw(chat_window_border);
				window.getInternal().draw(chat_text);
			}
		}
	}
}
