#ifndef IRONVEIN_APP_APP
#define IRONVEIN_APP_APP

// local
#include "app/appcfg.h"
#include "ui/window.h"
#include "state/gamestate.h"
#include "ui/interface.h"
#include "net/server.h"
#include "net/multiplexer.h"
#include "net/client.h"

// standard
#include "memory"

namespace IronVein
{
	namespace App
	{
		/* class that encapsulates a single app instance */
		class App
		{
			AppCfg _app_cfg;
			bool _running;

			std::shared_ptr<State::GameState> _game_state;
			std::shared_ptr<Game::Game> _game;

			std::shared_ptr<Net::Client> _client;
			std::shared_ptr<Net::Server> _server;
			std::shared_ptr<Net::Multiplexer> _multiplexer;

			UI::Window _main_window;
			std::shared_ptr<UI::Interface> _interface;

		public:
			App();
			void init(int argc = 0, char* argv[] = nullptr);
			void parseArgs(int argc, char* argv[]);
			int run();
			void close();
		};
	}
}

#endif
