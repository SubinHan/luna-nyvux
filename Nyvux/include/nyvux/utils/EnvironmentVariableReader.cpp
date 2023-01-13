#include "EnvironmentVariableReader.h"
#include <Windows.h>

using namespace nyvux;
using namespace std;



const string EnvironmentVariableReader::GetEnv(string Key)
{
	DWORD BufferSize = 65535;

	string Variable;
	Variable.resize(BufferSize);
	BufferSize = GetEnvironmentVariableA(Key.c_str(), &Variable[0], BufferSize);
	if (!BufferSize)
		Variable.resize(BufferSize);

	return Variable;
}

const wstring EnvironmentVariableReader::GetEnv(wstring Key)
{
	DWORD BufferSize = 65535;
	std::wstring Variable;
	Variable.resize(BufferSize);
	BufferSize = GetEnvironmentVariableW(Key.c_str(), &Variable[0], BufferSize);
	if (!BufferSize)
		Variable.resize(BufferSize);
	
	return Variable;
}
