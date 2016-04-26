#ifndef IRONVEIN_GAME_WORLDGENERATOR
#define IRONVEIN_GAME_WORLDGENERATOR

// local
#include "state/gamestate.h"

namespace IronVein
{
	namespace Game
	{
		void GenerateWorld(State::GameState& game_state);
		void GenerateOverworld(State::WorldState& world_state);
		void GenerateRegion(State::RegionState& region_state);
	}
}

#endif
