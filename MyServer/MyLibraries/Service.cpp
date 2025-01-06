#include "pch.h"
#include "Service.h"
#include "Listener.h"

Service::Service(
	shared_ptr<CPCore>CPCoreRef,
	NetAddress address,
	SessionFactory sessionFactory,
	uint32_t maxSessionCount,
	ServiceType type
) :
	_CPCoreRef(CPCoreRef),
	_address(address),
	_sessionFactory(sessionFactory),
	_maxSessionCount(maxSessionCount),
	_type(type)
{ }

ServerService::ServerService(shared_ptr<CPCore>CPCoreRef,
	NetAddress address,
	SessionFactory sessionFactory,
	uint32_t maxSessionCount
) :
	Service(CPCoreRef, address, sessionFactory, maxSessionCount, ServiceType::Server)
{ }

void ServerService::StartAccept() {

}
