#ifndef IRONVEIN_STATE_WORLDSTATE
#define IRONVEIN_STATE_WORLDSTATE

// local
#include "util/type.h"
#include "state/regionstate.h"

// library
#include "glm/glm.hpp"

namespace IronVein
{
	namespace State
	{
		/* A class representing the voxel world component of a game */
		class WorldState
		{
			i32 _region_depth = 64;
			glm::ivec2 _region_size = glm::ivec2(64, 64);
			glm::ivec2 _size = glm::ivec2(64, 64);

			std::vector<RegionState> _regions;

		public:
			WorldState();
			void init();

			RegionState& getRegion(glm::ivec2 position);
			glm::ivec2 getSize();
			glm::ivec2 getRegionSize();
		};
	}
}

#endif
