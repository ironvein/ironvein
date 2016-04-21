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

			this->_main_window.init(this->_app_cfg.default_window_width, this->_app_cfg.default_window_height, true);
		}

		int App::run()
		{
			Util::output("Running App instance");

			while (true)
			{
				this->_main_window.display();
			}

			return 0;
		}
	}
}
