#pragma once
#include <sql.h>
#include <sqlext.h>

class DBConnection {
public:
	bool Connect(SQLHENV henv, const WCHAR* connectionString);
	void Clear();

	bool Execute(const WCHAR* query);
	bool Fetch();
	int32_t GetRowCount();
	void Unbind();

public:
	bool BindParam(SQLUSMALLINT paramIndex, SQLSMALLINT cType, SQLSMALLINT sqlType, SQLULEN len, SQLPOINTER ptr, SQLLEN* index);
	bool BindCol(SQLUSMALLINT columnIndex, SQLSMALLINT cType, SQLULEN len, SQLPOINTER value, SQLLEN* index);
	void HandleError(SQLRETURN ret);

private:
	//SQL handle database connection
	SQLHDBC _connection = SQL_NULL_HANDLE;
	//SQL handle Statement
	SQLHSTMT _statement = SQL_NULL_HANDLE;
};

