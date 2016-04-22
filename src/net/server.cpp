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

		PlayerSocket::PlayerSocket()
		{
			// Constructor
		}

		void Server::init(std::weak_ptr<Game::Game> game, App::AppCfg app_cfg)
		{
			Util::output("Initialising Server instance");

			this->_game = game;

			this->_app_cfg = app_cfg;

			this->_listener.setBlocking(false);
			if (this->_listener.listen(this->_app_cfg.network_port) == sf::Socket::Done)
			{
				Util::output("Server is listening on port '" + std::to_string(this->_app_cfg.network_port) + "'");
			}
			else
			{
				Util::output("Server failed to listen on port '" + std::to_string(this->_app_cfg.network_port) + "'", Util::OutputMode::ERROR);
			}
		}

		void Server::tick()
		{
			std::shared_ptr<sf::TcpSocket> new_socket = std::make_shared<sf::TcpSocket>();
			if (this->_listener.accept(*new_socket) == sf::Socket::Done)
			{
				PlayerSocket new_player;
				new_player.id = this->_game.lock()->createPlayer().id;
				new_player.socket = new_socket;
				new_player.socket->setBlocking(false);
				this->_player_sockets.push_back(new_player);

				Util::output("Player with id '" + std::to_string(new_player.id) + "' and address '" + new_player.socket->getRemoteAddress().toString() + ":" + std::to_string(new_player.socket->getRemotePort()) + "' connected");
			}

			for (long i = 0; i < this->_player_sockets.size(); i ++)
			{
				sf::Packet data_packet;
				sf::Socket::Status status = this->_player_sockets[i].socket->receive(data_packet);

				if (status == sf::Socket::Done)
				{
					Util::output("Received message from player '" + std::to_string(this->_player_sockets[i].id) + "'");

					this->_game.lock()->passMessage(data_packet, i);
				}
				else if (status == sf::Socket::Status::Disconnected)
				{
					Util::output("Player with id '" + std::to_string(this->_player_sockets[i].id) + "' disconnected");
					this->disconnect(this->_player_sockets[i].id);
				}
			}

			this->_game.lock()->tick();
		}

		void Server::passReport(sf::Packet packet, int player_id)
		{
			for (long i = 0; i < this->_player_sockets.size(); i ++)
			{
				if (this->_player_sockets[i].id == player_id)
				{
					this->_player_sockets[i].socket->send(packet);
				}
			}
		}

		void Server::disconnect(long id)
		{
			for (long i = 0; i < this->_player_sockets.size(); i ++)
			{
				if (this->_player_sockets[i].id == id)
				{
					this->_player_sockets[i].socket->disconnect();
					this->_player_sockets[i] = this->_player_sockets.back();
					this->_player_sockets.pop_back();
				}
			}
		}
	}
}
