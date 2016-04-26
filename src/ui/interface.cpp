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

			for (int i = 0; i <= sf::Keyboard::Key::KeyCount; i ++)
				this->_key_states.push_back(false);

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

		bool Interface::getKey(sf::Keyboard::Key key)
		{
			if (key != -1)
				return this->_key_states[key];
			else
				return false;
		}

		void Interface::passEvent(sf::Event event)
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				{
					if (event.key.code != -1)
						this->_key_states[event.key.code] = true;
				}
				break;

			case sf::Event::KeyReleased:
				{
					if (event.key.code != -1)
						this->_key_states[event.key.code] = false;
				}
				break;

			case sf::Event::TextEntered:
				//Util::output(std::string("Key '") + static_cast<char>(event.text.unicode) + "' pressed!");
				break;

			default:
				break;
			}

			if (this->_current_widget >= 0 && this->_current_widget < (int)this->_widgets.size())
				this->_widgets[this->_current_widget]->passEvent(event, *this);
		}

		void Interface::sendMessage(sf::Packet packet)
		{
			this->_multiplexer.lock()->passMessage(packet);
		}

		void Interface::tick()
		{
			if (this->getKey(sf::Keyboard::Key::Left))
				this->_state.position.x --;
			if (this->getKey(sf::Keyboard::Key::Right))
				this->_state.position.x ++;
			if (this->getKey(sf::Keyboard::Key::Up))
				this->_state.position.y --;
			if (this->getKey(sf::Keyboard::Key::Down))
				this->_state.position.y ++;

			for (int i = 0; i < (int)this->_widgets.size(); i ++)
			{
				this->_widgets[i]->tick(*this, this->_current_widget == i);
			}
		}

		void Interface::render(Window& window)
		{
			this->_renderer.renderToWindow(*this->_game_state.lock(), window);

			for (int i = 0; i < (int)this->_widgets.size(); i ++)
			{
				this->_widgets[i]->render(*this, window, this->_current_widget == i);
			}
		}
	}
}
