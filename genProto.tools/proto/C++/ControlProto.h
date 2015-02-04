 
#ifndef _CONTROLPROTO_H_ 
#define _CONTROLPROTO_H_ 
 
const unsigned short EC_SUCCESS = 0; //success 
const unsigned short EC_ERROR = 1; //error 
const unsigned short EC_INVALID_PARAM = 1000; //invalid param 
const unsigned short EC_UNKNOWN_ID = 1001; //unknwon id 
 
struct TestIntegerData //测试 
{ 
	char _char;  
	unsigned char _uchar;  
	short _short;  
	unsigned short _ushort;  
	unsigned int _int;  
	unsigned int _uint;  
	long long _i64;  
	unsigned long long _ui128; //[already deleted] 
	unsigned long long _ui64;  
	TestIntegerData() 
	{ 
		_char = '\0'; 
		_uchar = 0; 
		_short = 0; 
		_ushort = 0; 
		_int = 0; 
		_uint = 0; 
		_i64 = 0; 
		_ui128 = 0; 
		_ui64 = 0; 
	} 
}; 
zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const TestIntegerData & data) 
{ 
	zsummer::proto4z::Integer offset = ws.getStreamLen(); 
	unsigned long long tag = 383ULL; 
	ws << offset; 
	ws << tag; 
	ws << data._char; 
	ws << data._uchar; 
	ws << data._short; 
	ws << data._ushort; 
	ws << data._int; 
	ws << data._uint; 
	ws << data._i64; 
//	ws << data._ui128; //[already deleted] 
	ws << data._ui64; 
	ws.fixOriginalData(offset, ws.getStreamLen() - offset); 
	return ws; 
} 
zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, TestIntegerData & data) 
{ 
	zsummer::proto4z::Integer cursor = rs.getStreamUnreadLen(); 
	zsummer::proto4z::Integer sttLen = 0; 
	unsigned long long tag = 0; 
	rs >> sttLen; 
	rs >> tag; 
	if ( (1ULL << 0) & tag) 
	{ 
		rs >> data._char;  
	} 
	if ( (1ULL << 1) & tag) 
	{ 
		rs >> data._uchar;  
	} 
	if ( (1ULL << 2) & tag) 
	{ 
		rs >> data._short;  
	} 
	if ( (1ULL << 3) & tag) 
	{ 
		rs >> data._ushort;  
	} 
	if ( (1ULL << 4) & tag) 
	{ 
		rs >> data._int;  
	} 
	if ( (1ULL << 5) & tag) 
	{ 
		rs >> data._uint;  
	} 
	if ( (1ULL << 6) & tag) 
	{ 
		rs >> data._i64;  
	} 
	if ( (1ULL << 7) & tag) 
	{ 
		rs >> data._ui128;  
	} 
	if ( (1ULL << 8) & tag) 
	{ 
		rs >> data._ui64;  
	} 
	cursor = cursor - rs.getStreamUnreadLen(); 
	rs.skipOriginalData(sttLen - cursor); 
	return rs; 
} 
 
struct TestFloatData //测试 
{ 
	float _float;  
	double _double;  
	TestFloatData() 
	{ 
		_float = 0.0; 
		_double = 0.0; 
	} 
}; 
zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const TestFloatData & data) 
{ 
	zsummer::proto4z::Integer offset = ws.getStreamLen(); 
	unsigned long long tag = 3ULL; 
	ws << offset; 
	ws << tag; 
	ws << data._float; 
	ws << data._double; 
	ws.fixOriginalData(offset, ws.getStreamLen() - offset); 
	return ws; 
} 
zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, TestFloatData & data) 
{ 
	zsummer::proto4z::Integer cursor = rs.getStreamUnreadLen(); 
	zsummer::proto4z::Integer sttLen = 0; 
	unsigned long long tag = 0; 
	rs >> sttLen; 
	rs >> tag; 
	if ( (1ULL << 0) & tag) 
	{ 
		rs >> data._float;  
	} 
	if ( (1ULL << 1) & tag) 
	{ 
		rs >> data._double;  
	} 
	cursor = cursor - rs.getStreamUnreadLen(); 
	rs.skipOriginalData(sttLen - cursor); 
	return rs; 
} 
 
struct TestStringData //测试 
{ 
	std::string _string;  
}; 
zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const TestStringData & data) 
{ 
	zsummer::proto4z::Integer offset = ws.getStreamLen(); 
	unsigned long long tag = 1ULL; 
	ws << offset; 
	ws << tag; 
	ws << data._string; 
	ws.fixOriginalData(offset, ws.getStreamLen() - offset); 
	return ws; 
} 
zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, TestStringData & data) 
{ 
	zsummer::proto4z::Integer cursor = rs.getStreamUnreadLen(); 
	zsummer::proto4z::Integer sttLen = 0; 
	unsigned long long tag = 0; 
	rs >> sttLen; 
	rs >> tag; 
	if ( (1ULL << 0) & tag) 
	{ 
		rs >> data._string;  
	} 
	cursor = cursor - rs.getStreamUnreadLen(); 
	rs.skipOriginalData(sttLen - cursor); 
	return rs; 
} 
 
typedef std::vector<unsigned int> IntArray;  
 
typedef std::vector<TestIntegerData> TestIntegerDataArray;  
 
typedef std::vector<TestFloatData> TestFloatDataArray;  
 
typedef std::vector<TestStringData> TestStringDataArray;  
 
typedef std::map<std::string, TestIntegerData> TestIntegerDataMap;  
 
typedef std::map<std::string, TestFloatData> TestFloatDataMap;  
 
typedef std::map<std::string, TestStringData> TestStringDataMap;  
 
const unsigned short ID_P2P_EchoPack = 30003;  
struct P2P_EchoPack 
{ 
	TestIntegerDataArray _iarray;  
	TestFloatDataArray _farray;  
	TestStringDataArray _sarray;  
	TestIntegerDataMap _imap;  
	TestFloatDataMap _fmap;  
	TestStringDataMap _smap;  
	inline unsigned short GetProtoID() { return 30003;} 
	inline std::string GetProtoName() { return "ID_P2P_EchoPack";} 
}; 
zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const P2P_EchoPack & data) 
{ 
	zsummer::proto4z::Integer offset = ws.getStreamLen(); 
	unsigned long long tag = 63ULL; 
	ws << offset; 
	ws << tag; 
	ws << data._iarray; 
	ws << data._farray; 
	ws << data._sarray; 
	ws << data._imap; 
	ws << data._fmap; 
	ws << data._smap; 
	ws.fixOriginalData(offset, ws.getStreamLen() - offset); 
	return ws; 
} 
zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, P2P_EchoPack & data) 
{ 
	zsummer::proto4z::Integer cursor = rs.getStreamUnreadLen(); 
	zsummer::proto4z::Integer sttLen = 0; 
	unsigned long long tag = 0; 
	rs >> sttLen; 
	rs >> tag; 
	if ( (1ULL << 0) & tag) 
	{ 
		rs >> data._iarray;  
	} 
	if ( (1ULL << 1) & tag) 
	{ 
		rs >> data._farray;  
	} 
	if ( (1ULL << 2) & tag) 
	{ 
		rs >> data._sarray;  
	} 
	if ( (1ULL << 3) & tag) 
	{ 
		rs >> data._imap;  
	} 
	if ( (1ULL << 4) & tag) 
	{ 
		rs >> data._fmap;  
	} 
	if ( (1ULL << 5) & tag) 
	{ 
		rs >> data._smap;  
	} 
	cursor = cursor - rs.getStreamUnreadLen(); 
	rs.skipOriginalData(sttLen - cursor); 
	return rs; 
} 
 
#endif 
