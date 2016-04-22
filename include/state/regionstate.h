#ifndef IRONVEIN_STATE_REGIONSTATE
#define IRONVEIN_STATE_REGIONSTATE

// local
#include "state/columnstate.h"

// standard
#include "vector"

namespace IronVein
{
	namespace State
	{
		/* A class representing a single loaded in-game region */
		class RegionState
		{
			std::vector<ColumnState> _columns;
		};
	}
}

#endif
