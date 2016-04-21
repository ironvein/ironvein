#ifndef IRONVEIN_STATE_GAMESTATE
#define IRONVEIN_STATE_GAMESTATE

// local
#include "state/worldstate.h"

namespace IronVein
{
	namespace State
	{
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
