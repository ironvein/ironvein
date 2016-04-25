// local
#include "net/server.h"
#include "util/output.h"
#include "game/worldgenerator.h"

namespace IronVein
{
	namespace Game
	{
		Game::Game()
		{
			// Constructor
		}

		void Game::init(std::weak_ptr<State::GameState> game_state, App::AppMode mode)
		{
			Util::output("Initialising Game instance");

			this->_game_state = game_state;
			this->_mode = mode;

			if (this->_mode == App::AppMode::SERVER || this->_mode == App::AppMode::LOCAL)
			{
				GenerateWorld(*this->_game_state.lock());
			}
		}

		void Game::giveMultiplexer(std::weak_ptr<Net::Multiplexer> multiplexer)
		{
			this->_multiplexer = multiplexer;
		}

		void Game::passMessage(sf::Packet packet, long player_id)
		{
			sf::Uint64 type;
			packet >> type;
			if ((Net::MessageType)type == Net::MessageType::CHAT_MESSAGE)
			{
				std::string message;
				packet >> message;

				Util::output("Player '" + std::to_string(player_id) + "' : '" + message + "'");

				this->_game_state.lock()->getChatState().addMessage(message);

				std::vector<State::Player> players = this->_game_state.lock()->getPlayerState().getPlayers();
				for (int i = 0; i < (int)players.size(); i ++)
				{
					sf::Uint64 type = (long)Net::ReportType::CHAT_MESSAGE;
					sf::Packet new_packet;
					new_packet << type << "Player " + std::to_string(player_id) + ": " + message;

					this->_multiplexer.lock()->passReportTo(new_packet, players[i].id);
				}
			}
		}

		void Game::passReport(sf::Packet packet)
		{
			sf::Uint64 type;
			packet >> type;
			if ((Net::ReportType)type == Net::ReportType::CHAT_MESSAGE)
			{
				std::string message;
				packet >> message;

				Util::output("Game recieved chat message from server '" + message + "'");

				this->_game_state.lock()->getChatState().addMessage(message);
			}
		}

		void Game::tick()
		{
			// Tick
		}

		long Game::getNewPlayerID()
		{
			this->_player_id_count ++;
			return this->_player_id_count - 1;
		}

		State::Player& Game::createPlayer()
		{
			State::Player new_player;
			new_player.id = this->getNewPlayerID();

			this->_game_state.lock()->getPlayerState().getPlayers().push_back(new_player);
			return this->_game_state.lock()->getPlayerState().getPlayers().back();
		}
	}
}
