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
			std::string data_directory;

			u16 default_window_width;
			u16 default_window_height;
		};
	}
}

#endif
