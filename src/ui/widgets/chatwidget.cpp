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

			void ChatWidget::passEvent(sf::Event event, Interface& interface)
			{
				switch (event.type)
				{
				case sf::Event::TextEntered:
					switch (static_cast<char>(event.text.unicode))
					{
					case '\b':
						{
							if (this->_input_text.size() > 0)
								this->_input_text.pop_back();
						}
						break;

					case 13:
						{
							sf::Packet packet;
							sf::Uint64 type = (long)Net::MessageType::CHAT_MESSAGE;
							packet << type;
							packet << this->_input_text;

							interface.sendMessage(packet);

							this->_input_text = "";
						}
						break;

					default:
						this->_input_text += static_cast<char>(event.text.unicode);
						break;
					}
					break;

				case sf::Event::MouseButtonPressed:
					{
						if (event.mouseButton.button == sf::Mouse::Button::Left &&
							event.mouseButton.x > this->_pos.x && event.mouseButton.y > this->_pos.y &&
							event.mouseButton.x < this->_pos.x + this->_size.x && event.mouseButton.y < this->_pos.y + this->_size.y)
						{
							this->_drag = true;
							this->_drag_pos = glm::vec2(event.mouseButton.x, event.mouseButton.y) - this->_pos;
						}
					}
					break;

				case sf::Event::MouseButtonReleased:
					{
						if (event.mouseButton.button == sf::Mouse::Button::Left)
						{
							this->_drag = false;
						}
					}
					break;

				case sf::Event::MouseMoved:
					{
						if (this->_drag)
						{
							this->_pos = glm::vec2(event.mouseMove.x, event.mouseMove.y) - this->_drag_pos;
						}
					}
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
				chat_window_border.setPosition(sf::Vector2f(this->_pos.x, this->_pos.y));
				chat_window_border.setSize(sf::Vector2f(this->_size.x, this->_size.y));
				chat_window_border.setFillColor(sf::Color(0, 200, 0, 100));
				window.getInternal().draw(chat_window_border);

				sf::Text chat_text;
				chat_text.setString(this->_input_text);
				chat_text.setFont(interface.getDefaultFont());
				chat_text.setPosition(sf::Vector2f(this->_pos.x + 12, this->_pos.y + 12));
				chat_text.setCharacterSize(12);
				chat_text.setColor(sf::Color::White);
				window.getInternal().draw(chat_text);

				std::vector<std::string> messages = interface.getGameState().lock()->getChatState().getMessages();
				for (int i = 0; i < (int)messages.size(); i ++)
				{
					chat_text.setString(messages[messages.size() - i - 1]);
					chat_text.setPosition(sf::Vector2f(this->_pos.x + 12, this->_pos.y + 24 + i * 12));
					chat_text.setColor(sf::Color::Black);
					window.getInternal().draw(chat_text);
				}
			}
		}
	}
}
