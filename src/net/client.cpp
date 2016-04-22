// local
#include "net/client.h"
#include "util/output.h"

namespace IronVein
{
	namespace Net
	{
		Client::Client()
		{
			// Constructor
		}

		void Client::init(App::AppCfg app_cfg)
		{
			Util::output("Initialising Client instance");

			this->_app_cfg = app_cfg;

			Util::output("Connecting to '" + this->_app_cfg.network_address + "'");

			sf::Socket::Status status = this->_socket.connect(this->_app_cfg.network_address, this->_app_cfg.network_port);
			if (status == sf::Socket::Done)
			{
				Util::output("Connected successfully");
				this->_connected = true;
			}
			else
			{
				Util::output("Connection failed");
				this->_connected = false;
			}
		}

		void Client::passMessage(MessageType type, const void* data, umem size)
		{
			if (!this->_connected)
			{
				Util::output("Sending message failed: Not connected to server", Util::OutputMode::ERROR);
				return;
			}

			Util::output("Sending message to '" + this->_app_cfg.network_address + "'");
		}
	}
}
