#include "pch.h"
#include "Service.h"
#include "Listener.h"

Service::Service(
	shared_ptr<CPCore>CPCoreRef,
	NetAddress address,
	SessionFactory sessionFactory,
	uint32_t maxSessionCount) :
	_CPCoreRef(CPCoreRef),
	_address(address),
	_sessionFactory(sessionFactory),
	_maxSessionCount(maxSessionCount)
{ }
