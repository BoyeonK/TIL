#pragma once
#include "DBConnection.h"

class DBConnectionPool {
public:
	DBConnectionPool();
	~DBConnectionPool();

	bool Connect(int32_t connectionCount, const WCHAR* connectionString);
	void Clear();

	DBConnection* Pop();
	void Push(DBConnection* pConnection);

private:
	USE_RWLOCK;

	//SQL Handle Environment
	SQLHENV _environment = SQL_NULL_HANDLE;
	vector<DBConnection*> _connections;
};

