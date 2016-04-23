// local
#include "ui/widgets/overworldwidget.h"
#include "util/output.h"
#include "ui/interface.h"

namespace IronVein
{
	namespace UI
	{
		namespace Widgets
		{
			OverworldWidget::OverworldWidget()
			{
				// Constructor
			}

			OverworldWidget::~OverworldWidget()
			{
				// Destructor
			}

			void OverworldWidget::init(Interface& interface)
			{
				Util::output("Initialising OverworldWidget instance");
			}

			void OverworldWidget::passEvent(sf::Event event, Interface& interface)
			{
				// Pass Event
			}

			void OverworldWidget::tick(Interface& interface, bool has_focus)
			{
				// Tick
			}

			void OverworldWidget::render(Interface& interface, Window& window, bool has_focus)
			{
				if (this->_visible)
				{
					sf::RectangleShape window_border;
					window_border.setPosition(sf::Vector2f(this->_position.x, this->_position.y));
					window_border.setSize(sf::Vector2f(112, 112));
					window_border.setFillColor(sf::Color(100, 100, 100, 100));
					window.getInternal().draw(window_border);

					sf::RectangleShape tile;
					State::WorldState& world_state = interface.getGameState().lock()->getWorldState();

					for (int i = 0; i < 6; i ++)
					{
						for (int j = 0; j < 6; j ++)
						{
							glm::vec2 pos = this->_position + glm::vec2(8, 8) + glm::vec2(i, j) * 16.0f;
							tile.setPosition(sf::Vector2f(pos.x, pos.y));
							tile.setSize(sf::Vector2f(16, 16));
							State::RegionState& region_state = world_state.getRegion(glm::ivec2(i + interface.getState().position.x, j + interface.getState().position.y));
							tile.setFillColor(sf::Color(std::min(255, std::max(0, region_state.getProperties().zoffset_00 / 4)), 0, 0, 255));
							window.getInternal().draw(tile);
						}
					}
				}
			}
		}
	}
}
