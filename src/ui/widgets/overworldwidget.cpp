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
					window_border.setSize(sf::Vector2f(this->_size.x, this->_size.x));
					window_border.setFillColor(sf::Color(100, 100, 100, 100));
					window.getInternal().draw(window_border);

					sf::RectangleShape tile;
					State::WorldState& world_state = interface.getGameState().lock()->getWorldState();

					for (int i = 0; i < this->_size.x / 16; i ++)
					{
						for (int j = 0; j < this->_size.y / 16; j ++)
						{
							int xx = interface.getState().position.x + i;
							int yy = interface.getState().position.y + j;
							if (xx < 0 || yy < 0 || xx >= world_state.getSize().x || yy >= world_state.getSize().y)
								continue;

							glm::vec2 pos = this->_position + glm::vec2((this->_size.x % 16) / 2, (this->_size.y % 16) / 2) + glm::vec2(i, j) * 16.0f;
							tile.setPosition(sf::Vector2f(pos.x, pos.y));
							tile.setSize(sf::Vector2f(16, 16));
							State::RegionState& region_state = world_state.getRegion(glm::ivec2(xx, yy));
							tile.setFillColor(sf::Color(std::min(255, std::max(0, (region_state.getProperties().zoffset_00 - 500) / 4)), 0, 0, 255));
							window.getInternal().draw(tile);
						}
					}
				}
			}
		}
	}
}
