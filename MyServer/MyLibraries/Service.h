#pragma once
#include <functional>
#include <set>
#include "Listener.h"
#include "Session.h"
#include "NetAddress.h"

enum class ServiceType : uint8_t {
	Server,
	Client
};

using SessionFactory = function<shared_ptr<Session>(void)>;

class Service {
public:
	Service(
		shared_ptr<CPCore>CPCoreRef,
		NetAddress address,
		SessionFactory sessionFactory,
		uint32_t maxSessionCount,
		ServiceType type
	);
	virtual ~Service() { }

	NetAddress GetAddress() { return _address; }
	shared_ptr<CPCore> GetCPCoreRef() { return _CPCoreRef; }

	

protected:
	shared_ptr<CPCore> _CPCoreRef;
	NetAddress _address;
	uint32_t _maxSessionCount;
	SessionFactory _sessionFactory;
	set<shared_ptr<Session>> _sessionRefs;
	ServiceType _type;
};

class ServerService : public Service {
public:
	ServerService(shared_ptr<CPCore>CPCoreRef,
		NetAddress address,
		SessionFactory sessionFactory,
		uint32_t maxSessionCount
	);
	~ServerService() { }
	void StartAccept();

private:
	shared_ptr<Listener> _ListenerRef;
};

