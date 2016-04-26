#ifndef IRONVEIN_STATE_REGIONSTATE
#define IRONVEIN_STATE_REGIONSTATE

// local
#include "state/columnstate.h"

// library
#include "glm/glm.hpp"

// standard
#include "vector"

namespace IronVein
{
	namespace State
	{
		enum class LoadMode
		{
			UNLOADED,
			LOADED,
		};

		struct RegionProperties
		{
			i32 zoffset_00 = 0;
			i32 zoffset_01 = 0;
			i32 zoffset_10 = 0;
			i32 zoffset_11 = 0;
		};

		/* A class representing a single loaded in-game region */
		class RegionState
		{
			RegionProperties _properties;
			std::vector<ColumnState> _columns;
			LoadMode _load_mode = LoadMode::UNLOADED;

		public:
			RegionState();
			void init();

			RegionProperties& getProperties();
			bool load();
			bool unload();
		};
	}
}

#endif
