#ifndef IRONVEIN_STATE_GAMESTATE
#define IRONVEIN_STATE_GAMESTATE

// local
#include "state/worldstate.h"

namespace IronVein
{
	namespace State
	{
		/* A class representing the state of an entire game */
		class GameState
		{
			WorldState _world_state;

		public:
			GameState();
			void init();
		};
	}
}

#endif
