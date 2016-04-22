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

		Player::Player()
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

		long Server::getNewPlayerID()
		{
			this->_player_id_count ++;
			return this->_player_id_count - 1;
		}

		void Server::passMessage(MessageType type, const void* data, umem size)
		{
			this->_game.lock()->passMessage(type, data, size);
		}

		void Server::tick()
		{
			std::shared_ptr<sf::TcpSocket> new_socket = std::make_shared<sf::TcpSocket>();
			if (this->_listener.accept(*new_socket) == sf::Socket::Done)
			{
				Player new_player;
				new_player.id = this->getNewPlayerID();
				new_player.socket = new_socket;
				new_player.socket->setBlocking(false);
				this->_players.push_back(new_player);

				Util::output("Player with id '" + std::to_string(new_player.id) + "' and address '" + new_player.socket->getRemoteAddress().toString() + ":" + std::to_string(new_player.socket->getRemotePort()) + "' connected");
			}

			for (long i = 0; i < this->_players.size(); i ++)
			{
				sf::Packet data_packet;
				sf::Socket::Status status = this->_players[i].socket->receive(data_packet);

				if (status == sf::Socket::Done)
				{
					Util::output("Received message from player '" + std::to_string(this->_players[i].id) + "'");

					sf::Uint64 message_type;
					data_packet >> message_type;

					if ((MessageType)message_type == MessageType::CHAT_MESSAGE)
					{
						std::string message;
						data_packet >> message;
						Util::output("Got chat message '" + message + "'");

						for (long i = 0; i < this->_players.size(); i ++)
							this->sendReport(this->_players[i].id, ReportType::CHAT_MESSAGE, message.c_str(), message.size());
					}
				}
				else if (status == sf::Socket::Status::Disconnected)
				{
					Util::output("Player with id '" + std::to_string(this->_players[i].id) + "' disconnected");
					this->disconnect(this->_players[i].id);
				}
			}

			this->_game.lock()->tick();
		}

		void Server::sendReport(long id, ReportType type, const void* data, umem size)
		{
			for (long i = 0; i < this->_players.size(); i ++)
			{
				if (this->_players[i].id == id)
				{
					sf::Packet data_packet;

					sf::Uint64 report_type = (long)type;
					std::string report_data = std::string(static_cast<const char*>(data), size);

					data_packet << report_type << report_data;

					this->_players[i].socket->send(data_packet);
				}
			}
		}

		void Server::disconnect(long id)
		{
			for (long i = 0; i < this->_players.size(); i ++)
			{
				if (this->_players[i].id == id)
				{
					this->_players[i].socket->disconnect();
					this->_players[i] = this->_players.back();
					this->_players.pop_back();
				}
			}
		}
	}
}
