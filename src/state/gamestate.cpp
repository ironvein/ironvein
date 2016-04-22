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

		WorldState& GameState::getWorldState()
		{
			return this->_world_state;
		}

		ChatState& GameState::getChatState()
		{
			return this->_chat_state;
		}

		PlayerState& GameState::getPlayerState()
		{
			return this->_player_state;
		}
	}
}
