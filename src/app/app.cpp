// local
#include "app/app.h"
#include "util/output.h"

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

			this->_game_state.init();
			this->_main_window.init(this->_app_cfg.default_window_width, this->_app_cfg.default_window_height);
			this->_renderer.init();
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
						this->_main_window.close();
						this->close();
						break;

					default:
						break;
					}
				}

				this->_renderer.renderToWindow(this->_game_state, this->_main_window);
				this->_main_window.update();
			}

			return 0;
		}

		void App::close()
		{
			Util::output("Closing App instance");
			this->_running = false;
		}
	}
}