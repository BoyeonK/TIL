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
{
	_listenerRef = make_shared<Listener>();
}

void ServerService::StartAccept() {
	weak_ptr<ServerService> ServerServiceWRef = static_pointer_cast<ServerService>(shared_from_this());
	_listenerRef->SetServerService(ServerServiceWRef);
	_listenerRef->StartAccept();
}
