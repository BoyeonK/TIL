#pragma once
#include <functional>
#include <set>
#include "Listener.h"
#include "NetAddress.h"
#include "Session.h"

using SessionFactory = function<shared_ptr<Session>(void)>;

class Service {
	Service(
		shared_ptr<CPCore>CPCoreRef,
		NetAddress address,
		SessionFactory sessionFactory,
		uint32_t maxSessionCount
	);
	virtual ~Service() { }

private:
	shared_ptr<CPCore> _CPCoreRef;
	NetAddress _address;
	uint32_t _maxSessionCount;
	SessionFactory _sessionFactory;
	Listener _Listener;
	set<shared_ptr<Session>> _sessionRefs;
};

