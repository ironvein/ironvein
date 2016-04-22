#ifndef IRONVEIN_NET_MESSAGE
#define IRONVEIN_NET_MESSAGE

namespace IronVein
{
	namespace Net
	{
		enum class MessageType
		{
			NONE			= 0,
			STAY_ALIVE		= 1,
			CHAT_MESSAGE	= 2,
		};

		enum class ReportType
		{
			NONE			= 0,
			STAY_ALIVE		= 1,
			CHAT_MESSAGE	= 2,
		};
	}
}

#endif
