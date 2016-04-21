#ifndef IRONVEIN_APP_APP
#define IRONVEIN_APP_APP

// local
#include "app/appcfg.h"
#include "ui/window.h"
#include "state/gamestate.h"
#include "ui/interface.h"

namespace IronVein
{
	namespace App
	{
		class App
		{
			AppCfg _app_cfg;
			bool _running;

			State::GameState _game_state;
			UI::Window _main_window;
			UI::Interface _interface;

		public:
			App();
			void init(int argc = 0, char* argv[] = nullptr);
			int run();
			void close();
		};
	}
}

#endif
