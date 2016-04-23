// local
#include "state/regionstate.h"
#include "util/output.h"

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
	}
}
