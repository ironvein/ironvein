#ifndef IRONVEIN_NET_MULTIPLEXER
#define IRONVEIN_NET_MULTIPLEXER

// local
#include "app/appcfg.h"
#include "net/message.h"

// library
#include "SFML/Network.hpp"

// standard
#include "memory"

namespace IronVein
{
	namespace Game
	{
		class Game;
	}

	namespace Net
	{
		class Client;
		class Server;

		class Multiplexer
		{
			App::AppMode _mode;

			std::weak_ptr<Net::Client> _client;
			std::weak_ptr<Net::Server> _server;
			std::weak_ptr<Game::Game> _game;

		public:
			Multiplexer();
			void init(std::weak_ptr<Net::Client> client, std::weak_ptr<Net::Server> server, std::weak_ptr<Game::Game> game, App::AppMode app_mode);

			void passMessage(sf::Packet packet);
			void passReportTo(sf::Packet packet, long player_id);
		};
	}
}

#endif
