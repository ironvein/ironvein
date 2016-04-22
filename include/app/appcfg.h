#ifndef IRONVEIN_APP_APPCFG
#define IRONVEIN_APP_APPCFG

// local
#include "util/type.h"

// standard
#include "string"

namespace IronVein
{
	namespace App
	{
		/* Modes to specify the operation of the app */
		enum class AppMode
		{
			NONE,	// The game will close immediately
			LOCAL,	// Local mode tells the game to emulate both a server and a client internally (i.e: single-player)
			CLIENT,	// Client mode tells the game to operate as a client of a networked game, with a UI
			SERVER,	// Server mode tells the game to operate as a server of a networked game, without a UI
		};

		/* A struct containing configuration data for an app instance */
		struct AppCfg
		{
			std::string data_directory = "data";

			u16 default_window_width = 800;
			u16 default_window_height = 600;

			AppMode mode = AppMode::LOCAL;
			std::string network_address = "";
			unsigned int network_port = 0;
		};
	}
}

#endif
