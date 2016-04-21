// local
#include "app/app.h"

// standard
#include "iostream"

int main(int argc, char* argv[])
{
	IronVein::App::App default_app;
	default_app.init(argc, argv);

	return default_app.run();
}
