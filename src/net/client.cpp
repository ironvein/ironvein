// local
#include "net/client.h"
#include "util/output.h"

namespace IronVein
{
	namespace Net
	{
		Client::Client()
		{
			// Constructor
		}

		void Client::init(std::weak_ptr<Game::Game> game, App::AppCfg app_cfg)
		{
			Util::output("Initialising Client instance");

			this->_game = game;
			this->_app_cfg = app_cfg;

			Util::output("Connecting to '" + this->_app_cfg.network_address + "'");

			sf::Socket::Status status = this->_socket.connect(this->_app_cfg.network_address, this->_app_cfg.network_port);
			this->_socket.setBlocking(false);
			if (status == sf::Socket::Done)
			{
				Util::output("Connected successfully");
				this->_connected = true;
			}
			else
			{
				Util::output("Connection failed");
				this->_connected = false;
			}
		}

		void Client::tick()
		{
			if (this->_connected)
			{
				sf::Packet data_packet;
				sf::Socket::Status status = this->_socket.receive(data_packet);

				if (status == sf::Socket::Done)
				{
					Util::output("Received report from server");

					this->_game.lock()->passReport(data_packet);
				}
				else if (status == sf::Socket::Status::Disconnected)
				{
					Util::output("Server disconnected");
					this->_connected = false;
				}
			}
		}

		void Client::passMessage(sf::Packet packet)
		{
			if (!this->_connected)
			{
				Util::output("Sending message failed: Not connected to server", Util::OutputMode::ERROR);
				return;
			}

			Util::output("Sending message to '" + this->_app_cfg.network_address + "'");

			this->_socket.send(packet);
		}
	}
}
