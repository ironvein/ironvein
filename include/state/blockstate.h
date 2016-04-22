#ifndef IRONVEIN_STATE_BLOCKSTATE
#define IRONVEIN_STATE_BLOCKSTATE

// local
#include "util/type.h"

namespace IronVein
{
	namespace State
	{
		/* A struct representing a single in-game block */
		struct BlockState
		{
			u32 type;
			u16 flags;
		};
	}
}

#endif
