// local
#include "server/server.h"
#include "util/output.h"

namespace IronVein
{
	namespace Server
	{
		Server::Server()
		{
			// Constructor
		}

		void Server::init(std::weak_ptr<State::GameState> game_state)
		{
			Util::output("Initialising Server instance");

			this->_game_state = game_state;
		}

		void Server::passMessage(Net::MessageType type, const void* data, umem size)
		{
			if (type == Net::MessageType::CHAT_MESSAGE)
			{
				std::string message = std::string(static_cast<const char*>(data), size);
				Util::output("Server recieved chat message '" + message + "'");
			}
		}
	}
}
