#ifndef IRONVEIN_GAME_GAME
#define IRONVEIN_GAME_GAME

// local
#include "net/message.h"
#include "util/type.h"
#include "state/gamestate.h"
#include "net/multiplexer.h"

// library
#include "SFML/Network.hpp"

// standard
#include "memory"

namespace IronVein
{
	namespace Game
	{
		class Game
		{
			std::weak_ptr<State::GameState> _game_state;
			std::weak_ptr<Net::Multiplexer> _multiplexer;

			long _player_id_count = 0;

		public:
			Game();
			void init(std::weak_ptr<State::GameState> game_state);
			void giveMultiplexer(std::weak_ptr<Net::Multiplexer> multiplexer);

			void passMessage(sf::Packet packet, long player_id);
			void passReport(sf::Packet packet);
			void tick();

			long getNewPlayerID();
			State::Player& createPlayer();
		};
	}
}

#endif
