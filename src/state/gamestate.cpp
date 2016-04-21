// local
#include "state/gamestate.h"
#include "util/output.h"

namespace IronVein
{
	namespace State
	{
		GameState::GameState()
		{
			// Constructor
		}

		void GameState::init()
		{
			Util::output("Initialising GameState instance");
		}
	}
}
