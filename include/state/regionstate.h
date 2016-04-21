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
		class RegionState
		{
			std::vector<ColumnState> _columns;
		};
	}
}

#endif
