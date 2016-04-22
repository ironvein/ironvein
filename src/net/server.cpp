// local
#include "net/server.h"
#include "util/output.h"

namespace IronVein
{
	namespace Net
	{
		Server::Server()
		{
			// Constructor
		}

		void Server::init(std::weak_ptr<State::GameState> game_state)
		{
			Util::output("Initialising Server instance");

			this->_game = std::make_shared<Game::Game>();
			this->_game->init(game_state);
		}

		void Server::passMessage(MessageType type, const void* data, umem size)
		{
			this->_game->passMessage(type, data, size);
		}
	}
}
