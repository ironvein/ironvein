// local
#include "state/playerstate.h"

namespace IronVein
{
	namespace State
	{
		PlayerState::PlayerState()
		{
			// Constructor
		}

		std::vector<Player>& PlayerState::getPlayers()
		{
			return this->_players;
		}
	}
}
