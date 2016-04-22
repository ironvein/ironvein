#ifndef IRONVEIN_UTIL_OUT
#define IRONVEIN_UTIL_OUT

// standard
#include "string"

namespace IronVein
{
	namespace Util
	{
		/* OutputMode used to specify how and when output is displayed */
		enum class OutputMode
		{
			DEBUG,
			INFO,
			ERROR,
			FAULT,
		};

		int output(std::string msg, OutputMode mode = OutputMode::DEBUG);
	}
}

#endif
