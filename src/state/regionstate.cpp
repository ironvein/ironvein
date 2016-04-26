// local
#include "state/regionstate.h"
#include "util/output.h"
#include "game/worldgenerator.h"

namespace IronVein
{
	namespace State
	{
		RegionState::RegionState()
		{
			// Constructor
		}

		void RegionState::init()
		{
			//Util::output("Initialising RegionState instance");
		}

		RegionProperties& RegionState::getProperties()
		{
			return this->_properties;
		}

		bool RegionState::load()
		{
			Game::GenerateRegion(*this);
			return true;
		}

		bool RegionState::unload()
		{
			return true;
		}
	}
}
