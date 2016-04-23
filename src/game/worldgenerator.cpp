// local
#include "game/worldgenerator.h"
#include "util/output.h"
#include "util/generation/noise.h"

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

			for (int i = 0; i < world_state.getSize().x; i ++)
			{
				for (int j = 0; j < world_state.getSize().y; j ++)
				{
					float z_00 = 1000.0f + Util::Generation::ValueNoise2D(i, j,			500.0f, 16.0f, 3, 0.5f);
					float z_01 = 1000.0f + Util::Generation::ValueNoise2D(i, j + 1,		500.0f, 16.0f, 3, 0.5f);
					float z_10 = 1000.0f + Util::Generation::ValueNoise2D(i + 1, j,		500.0f, 16.0f, 3, 0.5f);
					float z_11 = 1000.0f + Util::Generation::ValueNoise2D(i + 1, j + 1,	500.0f, 16.0f, 3, 0.5f);

					State::RegionState& region_state = world_state.getRegion(glm::ivec2(i, j));

					region_state.getProperties().zoffset_00 = (int)z_00;
					region_state.getProperties().zoffset_01 = (int)z_01;
					region_state.getProperties().zoffset_10 = (int)z_10;
					region_state.getProperties().zoffset_11 = (int)z_11;
				}
			}

			Util::output("Generated overworld");
		}
	}
}
