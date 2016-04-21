// local
#include "ui/interface.h"
#include "util/output.h"

namespace IronVein
{
	namespace UI
	{
		Interface::Interface()
		{
			// Constructor
		}

		void Interface::init(State::GameState* game_state)
		{
			Util::output("Initialising Interface instance");

			this->_game_state = game_state;

			this->_renderer.init();
		}

		void Interface::render(Window& window)
		{
			if (this->_game_state != nullptr)
				this->_renderer.renderToWindow(*this->_game_state, window);
		}
	}
}
