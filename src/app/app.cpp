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

			// Parse command-line arguments
			this->parseArgs(argc, argv);

			// Init the GameState
			this->_game_state = std::make_shared<State::GameState>();
			this->_game_state->init();

			// Init the Game
			this->_game = std::make_shared<Game::Game>();
			this->_game->init(std::weak_ptr<State::GameState>(this->_game_state), this->_app_cfg.mode);

			// Init the Server
			if (this->_app_cfg.mode == AppMode::SERVER)
			{
				this->_server = std::make_shared<Net::Server>();
				this->_server->init(std::weak_ptr<Game::Game>(this->_game), this->_app_cfg);
			}

			// Init the Client
			if (this->_app_cfg.mode == AppMode::CLIENT)
			{
				this->_client = std::make_shared<Net::Client>();
				this->_client->init(std::weak_ptr<Game::Game>(this->_game), this->_app_cfg);
			}

			// Init the Multiplexer
			this->_multiplexer = std::make_shared<Net::Multiplexer>();
			this->_multiplexer->init(this->_client, this->_server, this->_game, this->_app_cfg.mode);

			// Link the Game to the Multiplexer
			this->_game->giveMultiplexer(std::weak_ptr<Net::Multiplexer>(this->_multiplexer));

			// Init the Window and Interface
			if (this->_app_cfg.mode == AppMode::LOCAL || this->_app_cfg.mode == AppMode::CLIENT)
			{
				this->_main_window.init(this->_app_cfg.default_window_width, this->_app_cfg.default_window_height);
				this->_main_window.setTitle(Config::project_name + " " + Config::project_version);

				this->_interface = std::make_shared<UI::Interface>();
				this->_interface->init(std::weak_ptr<State::GameState>(this->_game_state), this->_multiplexer, this->_app_cfg);
			}
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
						this->_interface->passEvent(event);
						break;
					}
				}

				if (this->_app_cfg.mode == AppMode::CLIENT)
					this->_client->tick();

				if (this->_app_cfg.mode == AppMode::SERVER)
					this->_server->tick();

				if (this->_app_cfg.mode == AppMode::LOCAL || this->_app_cfg.mode == AppMode::CLIENT)
				{
					this->_interface->tick();
					
					this->_interface->render(this->_main_window);
					this->_main_window.update();
				}
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
