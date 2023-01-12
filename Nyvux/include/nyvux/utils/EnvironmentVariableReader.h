#pragma once

#include <string>

namespace nyvux
{
	class EnvironmentVariableReader
	{
	public:
		static const std::string GetEnv(std::string Key);
	};
}