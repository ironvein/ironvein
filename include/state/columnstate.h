#ifndef IRONVEIN_STATE_COLUMNSTATE
#define IRONVEIN_STATE_COLUMNSTATE

// local
#include "util/type.h"
#include "state/blockstate.h"

// standard
#include "vector"

namespace IronVein
{
	namespace State
	{
		struct ColumnState
		{
			i32 _zoffset = 0;
			std::vector<BlockState> _blocks;
		};
	}
}

#endif
