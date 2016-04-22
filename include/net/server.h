#ifndef IRONVEIN_NET_SERVER
#define IRONVEIN_NET_SERVER

// local
#include "net/message.h"
#include "util/type.h"
#include "state/gamestate.h"
#include "game/game.h"

// standard
#include "memory"

namespace IronVein
{
	namespace Net
	{
		class Server
		{
			std::shared_ptr<Game::Game> _game;

		public:
			Server();
			void init(std::weak_ptr<State::GameState> game_state);
			void passMessage(MessageType type, const void* data, umem size);
		};
	}
}

#endif
