#include "pch.h"
#include "DBConnectionPool.h"

DBConnectionPool::DBConnectionPool() {
}

DBConnectionPool::~DBConnectionPool() {
    Clear();
}

bool DBConnectionPool::Connect(int32_t connectionCount, const WCHAR* connectionString) {
    WRITE_RWLOCK;
    //서버 띄울때 한번! 연결한다.

    //1번째 인자, 사유
    if (SQL_SUCCESS != ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &_environment))
        return false;

    //ODBC버전 설정
    if (SQL_SUCCESS != ::SQLSetEnvAttr(_environment, SQL_ATTR_ODBC_VERSION, reinterpret_cast<SQLPOINTER>(SQL_OV_ODBC3), 0))
        return false;
    
    for (int32_t i = 0; i < connectionCount; i++) {
        DBConnection* pConnection = new DBConnection;
        if (false == pConnection->Connect(_environment, connectionString))
            return false;

        _connections.push_back(pConnection);
    }
    return true;
}

void DBConnectionPool::Clear() {
    WRITE_RWLOCK;

    if (_environment != SQL_NULL_HANDLE) {
        ::SQLFreeHandle(SQL_HANDLE_ENV, _environment);
        _environment = SQL_NULL_HANDLE;
    }

    for (DBConnection* pConnection : _connections)
        delete pConnection;

    _connections.clear();
}

DBConnection* DBConnectionPool::Pop() {
    WRITE_RWLOCK;
    if (_connections.empty())
        return nullptr;

    DBConnection* pConnection = _connections.back();
    _connections.pop_back();
    return pConnection;
}

void DBConnectionPool::Push(DBConnection* pConnection) {
    WRITE_RWLOCK;
    _connections.push_back(pConnection);
}
