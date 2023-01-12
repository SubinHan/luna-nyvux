#include "EnvironmentVariableReader.h"
#include <cstdlib>

using namespace nyvux;
using namespace std;

const string EnvironmentVariableReader::GetEnv(string Key)
{
	char* env = nullptr;
	size_t len{};
	_dupenv_s(&env, &len, Key.c_str());

	if (env == nullptr)
		return string{};

	return string(env, len);
}
