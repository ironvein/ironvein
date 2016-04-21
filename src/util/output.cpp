// local
#include "util/output.h"

// standard
#include "iostream"

namespace IronVein
{
	namespace Util
	{
		int output(std::string msg, OutputType type)
		{
			switch(type)
			{
			case OutputType::DEBUG:
				std::cout << "[ DEBUG ] ";
				break;
			case OutputType::INFO:
				std::cout << "[ INFO  ] ";
				break;
			case OutputType::ERROR:
				std::cout << "[ ERROR ] ";
				break;
			case OutputType::FAULT:
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
