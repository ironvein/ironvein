// local
#include "app/app.h"
#include "util/output.h"

namespace IronVein
{
	namespace App
	{
		App::App()
		{
			Util::output("Created App instance");
		}

		void App::init(int argc, char* argv[])
		{
			Util::output("Initialising App instance");
		}

		int App::run()
		{
			Util::output("Running App instance");

			return 0;
		}
	}
}
