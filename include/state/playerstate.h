#ifndef IRONVEIN_STATE_PLAYERSTATE
#define IRONVEIN_STATE_PLAYERSTATE

// standard
#include "string"
#include "vector"

namespace IronVein
{
	namespace State
	{
		struct Player
		{
			long id;
			std::string name;
		};

		class PlayerState
		{
			std::vector<Player> _players;

		public:
			PlayerState();
			std::vector<Player>& getPlayers();
		};
	}
}

#endif
