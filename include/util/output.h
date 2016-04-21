#ifndef IRONVEIN_UTIL_OUT
#define IRONVEIN_UTIL_OUT

// standard
#include "string"

namespace IronVein
{
	namespace Util
	{
		enum class OutputType
		{
			DEBUG,
			INFO,
			ERROR,
			FAULT,
		};

		int output(std::string msg, OutputType type = OutputType::DEBUG);
	}
}

#endif
