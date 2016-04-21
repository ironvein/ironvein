// local
#include "ui/renderer.h"
#include "util/output.h"

namespace IronVein
{
	namespace UI
	{
		Renderer::Renderer()
		{
			// Constructor
		}

		void Renderer::init()
		{
			Util::output("Initialising Renderer instance");
		}

		void Renderer::renderToWindow(State::GameState& game_state, Window& window)
		{
			window.clear(sf::Color(200, 230, 255));
		}
	}
}
