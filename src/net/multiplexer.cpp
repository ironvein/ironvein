// local
#include "net/multiplexer.h"
#include "server/server.h"
#include "ui/interface.h"
#include "util/output.h"

namespace IronVein
{
	namespace Net
	{
		Multiplexer::Multiplexer()
		{
			// Constructor
		}

		void Multiplexer::init(std::weak_ptr<Server::Server> server, std::weak_ptr<UI::Interface> interface, App::AppMode app_mode)
		{
			Util::output("Initialising Multiplexer instance");

			this->_server = server;
			this->_interface = interface;
			this->_mode = app_mode;
		}

		void Multiplexer::passMessage(Net::MessageType type, const void* data, umem size)
		{
			if (this->_mode == App::AppMode::SERVER || this->_mode == App::AppMode::LOCAL)
			{
				this->_server.lock()->passMessage(type, data, size);
			}
		}
	}
}
