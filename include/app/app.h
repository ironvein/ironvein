#ifndef IRONVEIN_APP_APP
#define IRONVEIN_APP_APP

// local
#include "app/appcfg.h"
#include "ui/window.h"

namespace IronVein
{
	namespace App
	{
		class App
		{
			AppCfg _app_cfg;

			UI::Window _main_window;

		public:
			App();
			void init(int argc = 0, char* argv[] = nullptr);
			int run();
		};
	}
}

#endif
