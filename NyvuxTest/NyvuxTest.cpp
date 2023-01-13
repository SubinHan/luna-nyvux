#include "pch.h"
#include "CppUnitTest.h"
#include "../Nyvux/include/nyvux/utils/EnvironmentVariableReader.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NyvuxTest
{
	using namespace nyvux;
	using namespace std;

	TEST_CLASS(UtilTest)
	{
	public:
		
		TEST_METHOD(TestGetEnvWithPath)
		{
			string Variable = EnvironmentVariableReader::GetEnv("Path");
			
			Assert::IsTrue(!Variable.empty());
			Assert::IsTrue(Variable.find("AppData") != std::string::npos);
		}

		TEST_METHOD(TestGetEnvWithWeird)
		{
			string Variable = EnvironmentVariableReader::GetEnv("gofpv2945i91rmc,-=");

			Assert::IsTrue(Variable.empty());
		}
	};
}
