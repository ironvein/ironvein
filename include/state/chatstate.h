#ifndef IRONVEIN_STATE_CHATSTATE
#define IRONVEIN_STATE_CHATSTATE

// standard
#include "vector"
#include "string"

namespace IronVein
{
	namespace State
	{
		class ChatState
		{
			std::vector<std::string> _messages;

		public:
			std::vector<std::string>& getMessages();
			void addMessage(std::string message);
		};
	}
}

#endif
