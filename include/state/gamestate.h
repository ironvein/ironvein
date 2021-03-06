#ifndef IRONVEIN_STATE_GAMESTATE
#define IRONVEIN_STATE_GAMESTATE

// local
#include "state/worldstate.h"
#include "state/chatstate.h"
#include "state/playerstate.h"

namespace IronVein
{
	namespace State
	{
		/* A class representing the state of an entire game */
		class GameState
		{
			WorldState _world_state;
			ChatState _chat_state;
			PlayerState _player_state;

		public:
			GameState();
			void init();

			WorldState& getWorldState();
			ChatState& getChatState();
			PlayerState& getPlayerState();
		};
	}
}

#endif
