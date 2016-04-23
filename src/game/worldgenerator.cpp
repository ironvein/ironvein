// local
#include "game/worldgenerator.h"
#include "util/output.h"
#include "util/generation/perlin.h"

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
					Util::output("Generating overworld region (" + std::to_string(i) + ", " + std::to_string(j) + ")");

					float z_00 = Util::Generation::Perlin2D(i, j, 3, 1000, 32, 1);
					float z_01 = Util::Generation::Perlin2D(i, j + 1, 3, 1000, 32, 1);
					float z_10 = Util::Generation::Perlin2D(i + 1, j, 3, 1000, 32, 1);
					float z_11 = Util::Generation::Perlin2D(i + 1, j + 1, 3, 1000, 32, 1);

					State::RegionState& region_state = world_state.getRegion(glm::ivec2(i, j));

					region_state.getProperties().zoffset_00 = (int)z_00;
					region_state.getProperties().zoffset_01 = (int)z_01;
					region_state.getProperties().zoffset_10 = (int)z_10;
					region_state.getProperties().zoffset_11 = (int)z_11;
				}
			}
		}
	}
}
