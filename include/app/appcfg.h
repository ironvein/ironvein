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
		struct AppCfg
		{
			std::string data_directory = "data";

			u16 default_window_width = 800;
			u16 default_window_height = 600;
		};
	}
}

#endif
