#ifndef IRONVEIN_UI_INTERFACE
#define IRONVEIN_UI_INTERFACE

// local
#include "state/gamestate.h"
#include "ui/renderer.h"
#include "ui/window.h"

namespace IronVein
{
	namespace UI
	{
		class Interface
		{
			State::GameState* _game_state = nullptr;

			Renderer _renderer;

		public:
			Interface();
			void init(State::GameState* game_state);
			void render(Window& window);
		};
	}
}

#endif
