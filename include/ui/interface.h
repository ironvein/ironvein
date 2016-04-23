#ifndef IRONVEIN_UI_INTERFACE
#define IRONVEIN_UI_INTERFACE

// local
#include "state/gamestate.h"
#include "ui/renderer.h"
#include "ui/window.h"
#include "ui/widgets/widget.h"
#include "app/appcfg.h"
#include "net/multiplexer.h"
#include "ui/interfacestate.h"

// library
#include "SFML/Graphics.hpp"

// standard
#include "vector"
#include "memory"

namespace IronVein
{
	namespace UI
	{
		/* A class representing a UI frontend interface manager */
		class Interface
		{
			std::weak_ptr<State::GameState> _game_state;
			InterfaceState _state;

			App::AppCfg _app_cfg;
			std::weak_ptr<Net::Multiplexer> _multiplexer;

			std::vector<std::shared_ptr<Widgets::Widget>> _widgets;
			int _current_widget = -1;

			sf::Font _default_font;

			Renderer _renderer;

		public:
			Interface();
			void init(std::weak_ptr<State::GameState> game_state, std::weak_ptr<Net::Multiplexer> multiplexer, App::AppCfg app_cfg);

			void addWidget(std::shared_ptr<Widgets::Widget> widget);
			sf::Font& getDefaultFont();

			std::weak_ptr<State::GameState> getGameState();
			InterfaceState& getState();

			void sendMessage(sf::Packet packet);

			void passEvent(sf::Event event);
			void tick();

			void render(Window& window);
		};
	}
}

#endif
