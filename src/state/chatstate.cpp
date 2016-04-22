// local
#include "state/chatstate.h"

namespace IronVein
{
	namespace State
	{
		std::vector<std::string> ChatState::getMessages()
		{
			return this->_messages;
		}

		void ChatState::addMessage(std::string message)
		{
			this->_messages.push_back(message);
		}
	}
}
