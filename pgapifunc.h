/*-------
 * Module:			pgapifunc.h
 *
 *-------
 */
#ifndef _PG_API_FUNC_H__
#define _PG_API_FUNC_H__

#include "psqlodbc.h"
#include <stdio.h>
#include <string.h>

/*	Internal flags for catalog functions */
#define	PODBC_NOT_SEARCH_PATTERN	1L
#define	PODBC_SEARCH_PUBLIC_SCHEMA	(1L << 1)
/*	Internal flags for PGAPI_Exec... functions */
#define	PODBC_WITH_HOLD			1L
/*	Flags for the error handling */
#define	PODBC_ALLOW_PARTIAL_EXTRACT	1L
#define	PODBC_ERROR_CLEAR		(1L << 1)

RETCODE SQL_API PGAPI_AllocConnect(HENV EnvironmentHandle,
				   HDBC FAR * ConnectionHandle);
RETCODE SQL_API PGAPI_AllocEnv(HENV FAR * EnvironmentHandle);
RETCODE SQL_API PGAPI_AllocStmt(HDBC ConnectionHandle,
				HSTMT *StatementHandle);
RETCODE SQL_API PGAPI_BindCol(	
			HSTMT hstmt,
			SQLUSMALLINT icol, 
			SQLSMALLINT fCType,
			PTR rgbValue, 
			SQLINTEGER cbValueMax,
			SQLINTEGER *pcbValue);
RETCODE SQL_API PGAPI_Cancel(HSTMT StatementHandle);
RETCODE SQL_API PGAPI_Columns(HSTMT StatementHandle,
			  SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
			  SQLCHAR *SchemaName, SQLSMALLINT NameLength2,
			  SQLCHAR *TableName, SQLSMALLINT NameLength3,
			  SQLCHAR *ColumnName, SQLSMALLINT NameLength4,
			  UWORD flag);
RETCODE SQL_API PGAPI_Connect(HDBC ConnectionHandle,
			  SQLCHAR *ServerName, SQLSMALLINT NameLength1,
			  SQLCHAR *UserName, SQLSMALLINT NameLength2,
			  SQLCHAR *Authentication, SQLSMALLINT NameLength3);
RETCODE SQL_API PGAPI_DriverConnect(HDBC hdbc, HWND hwnd,
					UCHAR FAR * szConnStrIn, SWORD cbConnStrIn,
					UCHAR FAR * szConnStrOut, SWORD cbConnStrOutMax,
					SWORD FAR * pcbConnStrOut, UWORD fDriverCompletion);
RETCODE SQL_API PGAPI_BrowseConnect(HDBC hdbc,
					SQLCHAR *szConnStrIn, SQLSMALLINT cbConnStrIn,
					SQLCHAR *szConnStrOut, SQLSMALLINT cbConnStrOutMax,
					SQLSMALLINT *pcbConnStrOut);
RETCODE SQL_API PGAPI_DataSources(HENV EnvironmentHandle,
				  SQLUSMALLINT Direction, SQLCHAR *ServerName,
				  SQLSMALLINT BufferLength1, SQLSMALLINT *NameLength1,
				  SQLCHAR *Description, SQLSMALLINT BufferLength2,
				  SQLSMALLINT *NameLength2);
RETCODE SQL_API PGAPI_DescribeCol(HSTMT StatementHandle,
				  SQLUSMALLINT ColumnNumber, SQLCHAR *ColumnName,
				  SQLSMALLINT BufferLength, SQLSMALLINT *NameLength,
				  SQLSMALLINT *DataType, SQLUINTEGER *ColumnSize,
				  SQLSMALLINT *DecimalDigits, SQLSMALLINT *Nullable);
RETCODE SQL_API PGAPI_Disconnect(HDBC ConnectionHandle);
RETCODE SQL_API PGAPI_Error(HENV henv,
			HDBC hdbc, 
			HSTMT hstmt,
			SQLCHAR *szSqlState,
			SQLINTEGER *pfNativeError,
			SQLCHAR *szErrorMsg, 
			SQLSMALLINT cbErrorMsgMax,
			SQLSMALLINT *pcbErrorMsg);
/* Helper functions for Error handling */
RETCODE SQL_API PGAPI_EnvError(HENV henv, 
			SWORD RecNumber,
			SQLCHAR *szSqlState, 
			SQLINTEGER *pfNativeError,
			SQLCHAR *szErrorMsg, 
			SQLSMALLINT cbErrorMsgMax,
			SQLSMALLINT *pcbErrorMsg, 
			UWORD flag);
RETCODE SQL_API PGAPI_ConnectError(HDBC hdbc, 
			SWORD RecNumber,
			SQLCHAR *szSqlState, 
			SQLINTEGER *pfNativeError,
			SQLCHAR *szErrorMsg, 
			SQLSMALLINT cbErrorMsgMax,
			SQLSMALLINT *pcbErrorMsg, 
			UWORD flag);
RETCODE SQL_API PGAPI_StmtError(HSTMT hstmt, 
			SWORD RecNumber,
			SQLCHAR *szSqlState, 
			SQLINTEGER *pfNativeError,
			SQLCHAR *szErrorMsg, 
			SQLSMALLINT cbErrorMsgMax,
			SQLSMALLINT *pcbErrorMsg, 
			UWORD flag);
RETCODE SQL_API PGAPI_ExecDirect(HSTMT hstmt,
			SQLCHAR *szSqlStr, 
			SQLINTEGER cbSqlStr, 
			UWORD flag);
RETCODE SQL_API PGAPI_Execute(HSTMT StatementHandle, UWORD flag);
RETCODE SQL_API PGAPI_Fetch(HSTMT StatementHandle);
RETCODE SQL_API PGAPI_FreeConnect(HDBC ConnectionHandle);
RETCODE SQL_API PGAPI_FreeEnv(HENV EnvironmentHandle);
RETCODE SQL_API PGAPI_FreeStmt(HSTMT StatementHandle,
			   SQLUSMALLINT Option);
RETCODE SQL_API PGAPI_GetConnectOption(HDBC ConnectionHandle,
					   SQLUSMALLINT Option, PTR Value);
RETCODE SQL_API PGAPI_GetCursorName(HSTMT StatementHandle,
					SQLCHAR *CursorName, SQLSMALLINT BufferLength,
					SQLSMALLINT *NameLength);
RETCODE SQL_API PGAPI_GetData(HSTMT hstmt,
				SQLUSMALLINT icol, 
				SQLSMALLINT fCType,
				PTR rgbValue, 
				SQLINTEGER cbValueMax,
				SQLINTEGER *pcbValue);
RETCODE SQL_API PGAPI_GetFunctions(HDBC ConnectionHandle,
				   SQLUSMALLINT FunctionId, SQLUSMALLINT *Supported);
RETCODE SQL_API PGAPI_GetFunctions30(HDBC ConnectionHandle,
					 SQLUSMALLINT FunctionId, SQLUSMALLINT *Supported);
RETCODE SQL_API PGAPI_GetInfo(HDBC ConnectionHandle,
			  SQLUSMALLINT InfoType, PTR InfoValue,
			  SQLSMALLINT BufferLength, SQLSMALLINT *StringLength);
RETCODE SQL_API PGAPI_GetInfo30(HDBC ConnectionHandle,
				SQLUSMALLINT InfoType, PTR InfoValue,
				SQLSMALLINT BufferLength, SQLSMALLINT *StringLength);
RETCODE SQL_API PGAPI_GetStmtOption(HSTMT StatementHandle,
					SQLUSMALLINT Option, PTR Value);
RETCODE SQL_API PGAPI_GetTypeInfo(HSTMT StatementHandle,
				  SQLSMALLINT DataType);
RETCODE SQL_API PGAPI_NumResultCols(HSTMT StatementHandle,
					SQLSMALLINT *ColumnCount);
RETCODE SQL_API PGAPI_ParamData(HSTMT StatementHandle,
				PTR *Value);
RETCODE SQL_API PGAPI_Prepare(HSTMT hstmt,
				SQLCHAR *szSqlStr, 
				SQLINTEGER cbSqlStr);
RETCODE SQL_API PGAPI_PutData(HSTMT hstmt,
				PTR rgbValue, 
				SQLINTEGER cbValue);
RETCODE SQL_API PGAPI_RowCount(HSTMT hstmt,
				SQLINTEGER *pcrow);
RETCODE SQL_API PGAPI_SetConnectOption(HDBC hdbc,
					SQLUSMALLINT fOption, 
					SQLPOINTER vParam);
RETCODE SQL_API PGAPI_SetCursorName(HSTMT StatementHandle,
					SQLCHAR *CursorName, SQLSMALLINT NameLength);
RETCODE SQL_API PGAPI_SetParam(HSTMT StatementHandle,
			   SQLUSMALLINT ParameterNumber, SQLSMALLINT ValueType,
			   SQLSMALLINT ParameterType, SQLUINTEGER LengthPrecision,
			   SQLSMALLINT ParameterScale, PTR ParameterValue,
			   SQLINTEGER *StrLen_or_Ind);
RETCODE SQL_API PGAPI_SetStmtOption(HSTMT hstmt,
					SQLUSMALLINT fOption, 
					SQLUINTEGER vParam);
RETCODE SQL_API PGAPI_SpecialColumns(HSTMT StatementHandle,
					 SQLUSMALLINT IdentifierType, SQLCHAR *CatalogName,
					 SQLSMALLINT NameLength1, SQLCHAR *SchemaName,
					 SQLSMALLINT NameLength2, SQLCHAR *TableName,
					 SQLSMALLINT NameLength3, SQLUSMALLINT Scope,
					 SQLUSMALLINT Nullable);
RETCODE SQL_API PGAPI_Statistics(HSTMT StatementHandle,
				 SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
				 SQLCHAR *SchemaName, SQLSMALLINT NameLength2,
				 SQLCHAR *TableName, SQLSMALLINT NameLength3,
				 SQLUSMALLINT Unique, SQLUSMALLINT Reserved);
RETCODE SQL_API PGAPI_Tables(HSTMT StatementHandle,
			 SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
			 SQLCHAR *SchemaName, SQLSMALLINT NameLength2,
			 SQLCHAR *TableName, SQLSMALLINT NameLength3,
			 SQLCHAR *TableType, SQLSMALLINT NameLength4);
RETCODE SQL_API PGAPI_Transact(HENV EnvironmentHandle,
			   HDBC ConnectionHandle, SQLUSMALLINT CompletionType);
RETCODE SQL_API PGAPI_ColAttributes(
					HSTMT hstmt,
					SQLUSMALLINT icol,
					SQLUSMALLINT fDescType,
					PTR rgbDesc,
					SQLSMALLINT cbDescMax,
					SQLSMALLINT *pcbDesc,
					SQLINTEGER *pfDesc);
RETCODE SQL_API PGAPI_ColumnPrivileges(
					   HSTMT hstmt,
					   SQLCHAR *szCatalogName,
					   SQLSMALLINT cbCatalogName,
					   SQLCHAR *szSchemaName,
					   SQLSMALLINT cbSchemaName,
					   SQLCHAR *szTableName,
					   SQLSMALLINT cbTableName,
					   SQLCHAR *szColumnName,
					   SQLSMALLINT cbColumnName);
RETCODE SQL_API PGAPI_DescribeParam(HSTMT hstmt,
					SQLUSMALLINT ipar,
					SQLSMALLINT *pfSqlType,
					SQLUINTEGER *pcbColDef,
					SQLSMALLINT *pibScale,
					SQLSMALLINT *pfNullable);
RETCODE SQL_API PGAPI_ExtendedFetch(HSTMT hstmt,
					SQLUSMALLINT fFetchType,
					SQLINTEGER irow,
					SQLUINTEGER *pcrow,
					SQLUSMALLINT *rgfRowStatus,
					SQLINTEGER bookmark_offset,
					SQLINTEGER rowsetSize);
RETCODE SQL_API PGAPI_ForeignKeys(
				  HSTMT hstmt,
				  SQLCHAR *szPkCatalogName,
				  SQLSMALLINT cbPkCatalogName,
				  SQLCHAR *szPkSchemaName,
				  SQLSMALLINT cbPkSchemaName,
				  SQLCHAR *szPkTableName,
				  SQLSMALLINT cbPkTableName,
				  SQLCHAR *szFkCatalogName,
				  SQLSMALLINT cbFkCatalogName,
				  SQLCHAR *szFkSchemaName,
				  SQLSMALLINT cbFkSchemaName,
				  SQLCHAR *szFkTableName,
				  SQLSMALLINT cbFkTableName);
RETCODE SQL_API PGAPI_MoreResults(
				  HSTMT hstmt);
RETCODE SQL_API PGAPI_NativeSql(
				HDBC hdbc,
				SQLCHAR *szSqlStrIn,
				SQLINTEGER cbSqlStrIn,
				SQLCHAR *szSqlStr,
				SQLINTEGER cbSqlStrMax,
				SQLINTEGER *pcbSqlStr);
RETCODE SQL_API PGAPI_NumParams(
				HSTMT hstmt,
				SQLSMALLINT *pcpar);
RETCODE SQL_API PGAPI_ParamOptions(HSTMT hstmt,
				   SQLUINTEGER crow,
				   SQLUINTEGER *pirow);
RETCODE SQL_API PGAPI_PrimaryKeys(
				  HSTMT hstmt,
				  SQLCHAR *szCatalogName,
				  SQLSMALLINT cbCatalogName,
				  SQLCHAR *szSchemaName,
				  SQLSMALLINT cbSchemaName,
				  SQLCHAR *szTableName,
				  SQLSMALLINT cbTableName);
RETCODE SQL_API PGAPI_ProcedureColumns(
					   HSTMT hstmt,
					   SQLCHAR *szCatalogName,
					   SQLSMALLINT cbCatalogName,
					   SQLCHAR *szSchemaName,
					   SQLSMALLINT cbSchemaName,
					   SQLCHAR *szProcName,
					   SQLSMALLINT cbProcName,
					   SQLCHAR *szColumnName,
					   SQLSMALLINT cbColumnName);
RETCODE SQL_API PGAPI_Procedures(
				 HSTMT hstmt,
				 SQLCHAR *szCatalogName,
				 SQLSMALLINT cbCatalogName,
				 SQLCHAR *szSchemaName,
				 SQLSMALLINT cbSchemaName,
				 SQLCHAR *szProcName,
				 SQLSMALLINT cbProcName);
RETCODE SQL_API PGAPI_SetPos(
			 HSTMT hstmt,
			 SQLUSMALLINT irow,
			 SQLUSMALLINT fOption,
			 SQLUSMALLINT fLock);
RETCODE SQL_API PGAPI_TablePrivileges(
					  HSTMT hstmt,
					  SQLCHAR *szCatalogName,
					  SQLSMALLINT cbCatalogName,
					  SQLCHAR *szSchemaName,
					  SQLSMALLINT cbSchemaName,
					  SQLCHAR *szTableName,
					  SQLSMALLINT cbTableName,
					  UWORD flag);
RETCODE SQL_API PGAPI_BindParameter(
					HSTMT hstmt,
					SQLUSMALLINT ipar,
					SQLSMALLINT fParamType,
					SQLSMALLINT fCType,
					SQLSMALLINT fSqlType,
					SQLUINTEGER cbColDef,
					SQLSMALLINT ibScale,
					PTR rgbValue,
					SQLINTEGER cbValueMax,
					SQLINTEGER *pcbValue);
RETCODE SQL_API PGAPI_SetScrollOptions(
					   HSTMT hstmt,
					   UWORD fConcurrency,
					   SDWORD crowKeyset,
					   UWORD crowRowset);

RETCODE SQL_API PGAPI_GetDiagRec(SQLSMALLINT HandleType, SQLHANDLE Handle,
		SQLSMALLINT RecNumber, SQLCHAR *Sqlstate,
		SQLINTEGER *NativeError, SQLCHAR *MessageText,
		SQLSMALLINT BufferLength, SQLSMALLINT *TextLength);
RETCODE SQL_API PGAPI_GetDiagField(SQLSMALLINT HandleType, SQLHANDLE Handle,
		SQLSMALLINT RecNumber, SQLSMALLINT DiagIdentifier,
		PTR DiagInfoPtr, SQLSMALLINT BufferLength,
		SQLSMALLINT *StringLengthPtr);
RETCODE SQL_API PGAPI_GetConnectAttr(HDBC ConnectionHandle,
			SQLINTEGER Attribute, PTR Value,
			SQLINTEGER BufferLength, SQLINTEGER *StringLength);
RETCODE SQL_API PGAPI_GetStmtAttr(HSTMT StatementHandle,
		SQLINTEGER Attribute, PTR Value,
		SQLINTEGER BufferLength, SQLINTEGER *StringLength);
RETCODE SQL_API PGAPI_SetConnectAttr(HDBC ConnectionHandle,
			SQLINTEGER Attribute, PTR Value,
			SQLINTEGER StringLength);
RETCODE SQL_API PGAPI_SetStmtAttr(HSTMT StatementHandle,
		SQLINTEGER Attribute, PTR Value,
		SQLINTEGER StringLength);
RETCODE SQL_API PGAPI_BulkOperations(HSTMT StatementHandle,
			SQLSMALLINT operation);
RETCODE SQL_API PGAPI_AllocDesc(HDBC ConnectionHandle,
				SQLHDESC *DescriptorHandle);
RETCODE SQL_API PGAPI_FreeDesc(SQLHDESC DescriptorHandle);
RETCODE SQL_API PGAPI_CopyDesc(SQLHDESC SourceDescHandle,
				SQLHDESC TargetDescHandle);
RETCODE SQL_API PGAPI_SetDescField(SQLHDESC DescriptorHandle,
			SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,
			PTR Value, SQLINTEGER BufferLength);
RETCODE SQL_API PGAPI_GetDescField(SQLHDESC DescriptorHandle,
			SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,
			PTR Value, SQLINTEGER BufferLength, SQLINTEGER *StringLength);
RETCODE SQL_API PGAPI_DescError(SQLHDESC hdesc, 
				SWORD RecNumber,
				SQLCHAR *szSqlState, 
				SQLINTEGER *pfNativeError,
				SQLCHAR *szErrorMsg, 
				SQLSMALLINT cbErrorMsgMax,
				SQLSMALLINT *pcbErrorMsg, 
				UWORD flag);
			
#endif   /* define_PG_API_FUNC_H__ */
