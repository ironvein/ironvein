// local
#include "ui/interface.h"
#include "util/output.h"
#include "ui/widgets/chatwidget.h"
#include "common/config.h"

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

		void Interface::passEvent(sf::Event event)
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				//Util::output("Key pressed!");
				break;

			case sf::Event::TextEntered:
				//Util::output(std::string("Key '") + static_cast<char>(event.text.unicode) + "' pressed!");
				break;

			default:
				break;
			}

			if (this->_current_widget >= 0 && this->_current_widget < this->_widgets.size())
				this->_widgets[this->_current_widget]->passEvent(event, *this);
		}

		void Interface::sendMessage(Net::MessageType type, const void* data, umem size)
		{
			this->_multiplexer.lock()->passMessage(type, data, size);
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
