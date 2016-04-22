// local
#include "game/worldgenerator.h"
#include "util/output.h"

namespace IronVein
{
	namespace Game
	{
		void GenerateWorld(State::GameState& game_state)
		{
			Util::output("Generating world");

			GenerateOverworld(game_state.getWorldState());
		}

		void GenerateOverworld(State::WorldState& world_state)
		{
			Util::output("Generating overworld");
		}
	}
}
