#ifndef IRONVEIN_SERVER_SERVER
#define IRONVEIN_SERVER_SERVER

// local
#include "net/message.h"
#include "util/type.h"
#include "state/gamestate.h"

// standard
#include "memory"

namespace IronVein
{
	namespace Server
	{
		class Server
		{
			std::weak_ptr<State::GameState> _game_state;

		public:
			Server();
			void init(std::weak_ptr<State::GameState> game_state);
			void passMessage(Net::MessageType type, const void* data, umem size);
		};
	}
}

#endif
