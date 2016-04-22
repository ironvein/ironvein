#ifndef IRONVEIN_GAME_GAME
#define IRONVEIN_GAME_GAME

// local
#include "net/message.h"
#include "util/type.h"
#include "state/gamestate.h"

// standard
#include "memory"

namespace IronVein
{
	namespace Game
	{
		class Game
		{
			std::weak_ptr<State::GameState> _game_state;

		public:
			Game();
			void init(std::weak_ptr<State::GameState> game_state);
			void passMessage(Net::MessageType type, const void* data, umem size);
			void passReport(Net::ReportType type, const void* data, umem size);
			void tick();
		};
	}
}

#endif
