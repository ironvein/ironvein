// local
#include "net/multiplexer.h"
#include "net/server.h"
#include "net/client.h"
#include "ui/interface.h"
#include "util/output.h"

namespace IronVein
{
	namespace Net
	{
		Multiplexer::Multiplexer()
		{
			// Constructor
		}

		void Multiplexer::init(std::weak_ptr<Net::Client> client, std::weak_ptr<Net::Server> server, std::weak_ptr<Game::Game> game, App::AppMode app_mode)
		{
			Util::output("Initialising Multiplexer instance");

			this->_client = client;
			this->_server = server;
			this->_game = game;
			this->_mode = app_mode;
		}

		void Multiplexer::passMessage(sf::Packet packet)
		{
			if (this->_mode == App::AppMode::CLIENT)
			{
				this->_client.lock()->passMessage(packet);
			}
			else if (this->_mode == App::AppMode::LOCAL)
			{
				this->_game.lock()->passMessage(packet, 0);
			}
		}

		void Multiplexer::passReportTo(sf::Packet packet, long player_id)
		{
			if (this->_mode == App::AppMode::SERVER)
			{
				this->_server.lock()->passReport(packet, player_id);
			}
		}
	}
}
