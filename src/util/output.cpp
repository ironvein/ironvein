// local
#include "util/output.h"

// standard
#include "iostream"

namespace IronVein
{
	namespace Util
	{
		int output(std::string msg, OutputMode mode)
		{
			switch (mode)
			{
			case OutputMode::DEBUG:
				std::cout << "[ DEBUG ] ";
				break;
			case OutputMode::INFO:
				std::cout << "[ INFO  ] ";
				break;
			case OutputMode::ERROR:
				std::cout << "[ ERROR ] ";
				break;
			case OutputMode::FAULT:
				std::cout << "[ FAULT ] ";
				break;
			default:
				std::cout << "[ NONE  ] ";
				break;
			}

			std::cout << msg << std::endl;
		}
	}
}
