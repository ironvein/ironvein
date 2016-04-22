#ifndef IRONVEIN_NET_CLIENT
#define IRONVEIN_NET_CLIENT

// local
#include "app/appcfg.h"
#include "net/message.h"

// library
#include "SFML/Network.hpp"

namespace IronVein
{
	namespace Net
	{
		class Client
		{
			sf::TcpSocket _socket;
			bool _connected = false;
			App::AppCfg _app_cfg;

		public:
			Client();
			void init(App::AppCfg app_cfg);
			void passMessage(MessageType type, const void* data, umem size);
		};
	}
}

#endif
