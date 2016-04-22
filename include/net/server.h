#ifndef IRONVEIN_NET_SERVER
#define IRONVEIN_NET_SERVER

// local
#include "net/message.h"
#include "util/type.h"
#include "state/gamestate.h"
#include "game/game.h"
#include "app/appcfg.h"

// library
#include "SFML/Network.hpp"

// standard
#include "memory"
#include "vector"

namespace IronVein
{
	namespace Net
	{
		struct PlayerSocket
		{
			long id;
			std::shared_ptr<sf::TcpSocket> socket;

			PlayerSocket();
		};

		class Server
		{
			sf::TcpListener _listener;

			App::AppCfg _app_cfg;
			std::weak_ptr<Game::Game> _game;
			std::vector<PlayerSocket> _player_sockets;

		public:
			Server();
			void init(std::weak_ptr<Game::Game> game, App::AppCfg app_cfg);

			void passReport(sf::Packet packet, int player_id);
			void disconnect(long id);
			void tick();
		};
	}
}

#endif
