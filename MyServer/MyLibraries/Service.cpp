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

shared_ptr<Session> Service::CreateSessionRef() {
	shared_ptr<Session> sessionRef = _sessionFactory();
	weak_ptr<Service> serviceWRef = shared_from_this();
	sessionRef->SetServiceWRef(serviceWRef);
	_CPCoreRef->Register(static_pointer_cast<CPObject>(sessionRef));
	return sessionRef;
}

void Service::AddSession(shared_ptr<Session> sessionRef) {
	WRITE_RWLOCK;
	_sessionRefs.insert(sessionRef);
}

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
