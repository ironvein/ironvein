#ifndef IRONVEIN_UI_RENDERER
#define IRONVEIN_UI_RENDERER

// local
#include "ui/window.h"
#include "state/gamestate.h"

namespace IronVein
{
	namespace UI
	{
		class Renderer
		{
		public:
			Renderer();
			void init();
			void renderToWindow(State::GameState& game_state, Window& window);
		};
	}
}

#endif
