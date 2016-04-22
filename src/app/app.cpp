// local
#include "app/app.h"
#include "util/output.h"
#include "common/config.h"

// standard
#include "cstdlib"

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

			this->parseArgs(argc, argv);

			// Before init, create instances
			this->_game_state = std::make_shared<State::GameState>();
			this->_game_state->init();

			this->_main_window.init(this->_app_cfg.default_window_width, this->_app_cfg.default_window_height);
			this->_main_window.setTitle(Config::project_name + " " + Config::project_version);

			this->_interface.init(std::weak_ptr<State::GameState>(this->_game_state), this->_app_cfg);
		}

		void App::parseArgs(int argc, char* argv[])
		{
			Util::output("Parsing App arguments");

			for (int i = 0; i < argc; i ++)
			{
				std::string arg = std::string(argv[i]);

				if (arg == "--server")
				{
					this->_app_cfg.mode = AppMode::SERVER;
					Util::output("Server mode enabled");
				}
				else if (arg == "--client")
				{
					this->_app_cfg.mode = AppMode::CLIENT;
					Util::output("Client mode enabled");
				}
				else if (arg == "--local")
				{
					this->_app_cfg.mode = AppMode::LOCAL;
					Util::output("Local mode enabled");
				}
				else if (arg == "--ip" && i < argc - 1)
				{
					i ++;
					std::string value = std::string(argv[i]);
					this->_app_cfg.network_address = value;
					Util::output("Network address set to " + value);
				}
				else if (arg == "--port" && i < argc - 1)
				{
					i ++;
					std::string value = std::string(argv[i]);
					this->_app_cfg.network_port = atoi(value.c_str());
					Util::output("Network port set to " + value);
				}
			}
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
