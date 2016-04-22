// local
#include "app/app.h"
#include "util/output.h"
#include "common/config.h"

namespace IronVein
{
	namespace App
	{
		App::App()
		{
			// Constructor
		}

		void App::init(int argc, char* argv[])
		{
			Util::output("Initialising App instance");

			// Before init, create instances
			this->_game_state = std::make_shared<State::GameState>();

			this->_game_state->init();

			this->_main_window.init(this->_app_cfg.default_window_width, this->_app_cfg.default_window_height);
			this->_main_window.setTitle(Config::project_name + " " + Config::project_version);

			this->_interface.init(std::weak_ptr<State::GameState>(this->_game_state), this->_app_cfg);
		}

		int App::run()
		{
			Util::output("Running App instance");

			this->_running = true;
			this->_main_window.setEnabled(true);

			while (this->_running)
			{
				std::vector<sf::Event> event_vector = this->_main_window.getEvents();

				for (sf::Event event : event_vector)
				{
					switch (event.type)
					{
					case sf::Event::Closed:
						this->close();
						break;

					default:
						this->_interface.passEvent(event);
						break;
					}
				}

				this->_interface.render(this->_main_window);
				this->_main_window.update();
			}

			return 0;
		}

		void App::close()
		{
			Util::output("Closing App instance");

			if (this->_main_window.isOpen())
				this->_main_window.close();

			this->_running = false;
		}
	}
}
