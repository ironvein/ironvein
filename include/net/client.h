#ifndef IRONVEIN_NET_CLIENT
#define IRONVEIN_NET_CLIENT

// local
#include "app/appcfg.h"
#include "net/message.h"
#include "state/gamestate.h"

// library
#include "SFML/Network.hpp"

// standard
#include "memory"

namespace IronVein
{
	namespace Net
	{
		class Client
		{
			sf::TcpSocket _socket;
			bool _connected = false;
			App::AppCfg _app_cfg;
			std::weak_ptr<State::GameState> _game_state;

		public:
			Client();
			void init(std::weak_ptr<State::GameState> game_state, App::AppCfg app_cfg);
			void passMessage(MessageType type, const void* data, umem size);
			void tick();
		};
	}
}

#endif
