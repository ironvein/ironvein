#ifndef IRONVEIN_NET_MULTIPLEXER
#define IRONVEIN_NET_MULTIPLEXER

// local
#include "app/appcfg.h"
#include "net/message.h"

// standard
#include "memory"

namespace IronVein
{
	namespace UI
	{
		class Interface;
	}

	namespace Net
	{
		class Client;
		class Server;

		class Multiplexer
		{
			App::AppMode _mode;

			std::weak_ptr<Net::Client> _client;
			std::weak_ptr<Net::Server> _server;
			std::weak_ptr<UI::Interface> _interface;

		public:
			Multiplexer();
			void init(std::weak_ptr<Net::Client> client, std::weak_ptr<Net::Server> server, std::weak_ptr<UI::Interface> interface, App::AppMode app_mode);

			void passMessage(Net::MessageType type, const void* data, umem size);
		};
	}
}

#endif
