#include "pch.h"
#include "DBConnection.h"

bool DBConnection::Connect(SQLHENV henv, const WCHAR* connectionString) {
	if (SQL_SUCCESS != ::SQLAllocHandle(SQL_HANDLE_DBC, henv, &_connection))
		return false;

	WCHAR stringBuffer[MAX_PATH] = { 0 };
	::wcscpy_s(stringBuffer, connectionString);

	WCHAR resultString[MAX_PATH] = { 0 };
	SQLSMALLINT resultStringLen = 0;
	SQLRETURN ret = ::SQLDriverConnectW(
		_connection,
		NULL,
		reinterpret_cast<SQLWCHAR*>(stringBuffer),
		_countof(stringBuffer),
		reinterpret_cast<SQLWCHAR*>(resultString),
		_countof(resultString),
		&resultStringLen,
		SQL_DRIVER_NOPROMPT
	);

	if (::SQLAllocHandle(SQL_HANDLE_STMT, _connection, &_statement) != SQL_SUCCESS)
		return false;

	return (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO);
}

void DBConnection::Clear() {
}

bool DBConnection::Execute(const WCHAR* query) {
	return false;
}

bool DBConnection::Fetch() {
	return false;
}

int32_t DBConnection::GetRowCount() {
	return int32_t();
}

void DBConnection::Unbind() {
}

bool DBConnection::BindParam(SQLUSMALLINT paramIndex, SQLSMALLINT cType, SQLSMALLINT sqlType, SQLULEN len, SQLPOINTER ptr, SQLLEN* index) {
	return false;
}

bool DBConnection::BindCol(SQLUSMALLINT columnIndex, SQLSMALLINT cType, SQLULEN len, SQLPOINTER value, SQLLEN* index) {
	return false;
}

void DBConnection::HandleError(SQLRETURN ret) {
}
