// local
#include "ui/interface.h"
#include "util/output.h"
#include "ui/widgets/chatwidget.h"
#include "common/config.h"
#include "ui/widgets/overworldwidget.h"

namespace IronVein
{
	namespace UI
	{
		Interface::Interface()
		{
			// Constructor
		}

		void Interface::init(std::weak_ptr<State::GameState> game_state, std::weak_ptr<Net::Multiplexer> multiplexer, App::AppCfg app_cfg)
		{
			Util::output("Initialising Interface instance");

			this->_game_state = game_state;
			this->_multiplexer = multiplexer;
			this->_app_cfg = app_cfg;

			// Load default resources
			this->_default_font.loadFromFile(this->_app_cfg.data_directory + "/commodore.ttf");

			// Create a few default widgets
			this->addWidget(std::make_shared<Widgets::ChatWidget>());
			this->addWidget(std::make_shared<IronVein::UI::Widgets::OverworldWidget>());
			this->_current_widget = 0;

			this->_renderer.init();
		}

		void Interface::addWidget(std::shared_ptr<Widgets::Widget> widget)
		{
			this->_widgets.push_back(widget);
			widget->init(*this);
		}

		sf::Font& Interface::getDefaultFont()
		{
			return this->_default_font;
		}

		std::weak_ptr<State::GameState> Interface::getGameState()
		{
			return this->_game_state;
		}

		InterfaceState& Interface::getState()
		{
			return this->_state;
		}

		void Interface::passEvent(sf::Event event)
		{
			bool cancel_pass = false;

			switch (event.type)
			{
			case sf::Event::KeyPressed:
				{
					cancel_pass = true;
					if (event.key.code == sf::Keyboard::Left)
						this->_state.position.x --;
					else if (event.key.code == sf::Keyboard::Right)
						this->_state.position.x ++;
					else if (event.key.code == sf::Keyboard::Up)
						this->_state.position.y --;
					else if (event.key.code == sf::Keyboard::Down)
						this->_state.position.y ++;
					else
						cancel_pass = false;
				}
				break;

			case sf::Event::TextEntered:
				//Util::output(std::string("Key '") + static_cast<char>(event.text.unicode) + "' pressed!");
				break;

			default:
				break;
			}

			if (!cancel_pass && this->_current_widget >= 0 && this->_current_widget < this->_widgets.size())
				this->_widgets[this->_current_widget]->passEvent(event, *this);
		}

		void Interface::sendMessage(sf::Packet packet)
		{
			this->_multiplexer.lock()->passMessage(packet);
		}

		void Interface::tick()
		{
			for (int i = 0; i < this->_widgets.size(); i ++)
			{
				this->_widgets[i]->tick(*this, this->_current_widget == i);
			}
		}

		void Interface::render(Window& window)
		{
			this->_renderer.renderToWindow(*this->_game_state.lock(), window);

			for (int i = 0; i < this->_widgets.size(); i ++)
			{
				this->_widgets[i]->render(*this, window, this->_current_widget == i);
			}
		}
	}
}
