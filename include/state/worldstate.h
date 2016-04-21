#ifndef IRONVEIN_STATE_WORLDSTATE
#define IRONVEIN_STATE_WORLDSTATE

// local
#include "util/type.h"
#include "state/regionstate.h"

// library
#include "glm/glm.hpp"

// standard
#include "map"

namespace IronVein
{
	namespace State
	{
		class WorldState
		{
			i32 _region_size = 64;
			i32 _region_depth = 64;
			i32 _world_width = 64;
			i32 _world_height = 64;

			std::map<glm::ivec3, RegionState> _regions;
		};
	}
}

#endif
