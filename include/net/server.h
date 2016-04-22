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
		struct Player
		{
			long id;
			std::shared_ptr<sf::TcpSocket> socket;

			Player();
		};

		class Server
		{
			sf::TcpListener _listener;

			App::AppCfg _app_cfg;
			std::weak_ptr<Game::Game> _game;
			std::vector<Player> _players;

			long _player_id_count = 0;

		public:
			Server();
			void init(std::weak_ptr<Game::Game> game, App::AppCfg app_cfg);

			long getNewPlayerID();
			void passMessage(MessageType type, const void* data, umem size);
			void sendReport(long id, ReportType type, const void* data, umem size);
			void disconnect(long id);
			void tick();
		};
	}
}

#endif
