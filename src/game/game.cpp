// local
#include "net/server.h"
#include "util/output.h"

namespace IronVein
{
	namespace Game
	{
		Game::Game()
		{
			// Constructor
		}

		void Game::init(std::weak_ptr<State::GameState> game_state)
		{
			Util::output("Initialising Game instance");

			this->_game_state = game_state;
		}

		void Game::passMessage(Net::MessageType type, const void* data, umem size)
		{
			if (type == Net::MessageType::CHAT_MESSAGE)
			{
				std::string message = std::string(static_cast<const char*>(data), size);
				Util::output("Server recieved chat message '" + message + "'");
			}
		}
	}
}
