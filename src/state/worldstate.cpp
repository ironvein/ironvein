// local
#include "state/worldstate.h"
#include "util/output.h"

namespace IronVein
{
	namespace State
	{
		WorldState::WorldState()
		{
			// Constructor
		}

		void WorldState::init()
		{
			Util::output("Initialising WorldState instance");

			for (long i = 0; i < this->_size.x * this->_size.y; i ++)
			{
				this->_regions.emplace_back();
				this->_regions.back().init();
			}
		}

		RegionState& WorldState::getRegion(glm::ivec2 position)
		{
			return this->_regions[position.y * this->_size.x + position.x];
		}

		glm::ivec2 WorldState::getSize()
		{
			return this->_size;
		}

		glm::ivec2 WorldState::getRegionSize()
		{
			return this->_region_size;
		}
	}
}
