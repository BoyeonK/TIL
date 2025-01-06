#pragma once
#include <functional>
#include <set>
#include "Listener.h"
#include "Session.h"
#include "NetAddress.h"

using SessionFactory = function<shared_ptr<Session>(void)>;

class Service {
public:
	Service(
		shared_ptr<CPCore>CPCoreRef,
		NetAddress address,
		SessionFactory sessionFactory,
		uint32_t maxSessionCount
	);
	virtual ~Service() { }

	NetAddress GetAddress() { return _address; }
	shared_ptr<CPCore> GetCPCoreRef() { return _CPCoreRef; }

private:
	shared_ptr<CPCore> _CPCoreRef;
	NetAddress _address;
	uint32_t _maxSessionCount;
	SessionFactory _sessionFactory;
	Listener _Listener;
	set<shared_ptr<Session>> _sessionRefs;
};

