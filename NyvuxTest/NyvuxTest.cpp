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

		TEST_METHOD(TestGetEnvWstringWithPath)
		{
			wstring Variable = EnvironmentVariableReader::GetEnv(L"Path");

			Assert::IsTrue(!Variable.empty());
			Assert::IsTrue(Variable.find(L"AppData") != std::wstring::npos);
		}

		TEST_METHOD(TestGetEnvWstringWithWeird)
		{
			string Variable = EnvironmentVariableReader::GetEnv("gofpv2945i91rmc,-=");

			Assert::IsTrue(Variable.empty());
		}

		TEST_METHOD(TestGetEnvStringWorksWell1)
		{
			string Variable = EnvironmentVariableReader::GetEnv("gofpv2945i91rmc,-=");

			Assert::IsTrue(Variable.empty());

			Variable.append("asd");

			Assert::IsFalse(Variable.empty());
			Assert::AreEqual(Variable, string("asd"));
		}

		TEST_METHOD(TestGetEnvStringWorksWell2)
		{
			string Variable = EnvironmentVariableReader::GetEnv("Path");

			Assert::IsFalse(Variable.empty());
			Assert::AreNotEqual(*(Variable.rbegin()), '\0');

			Variable.append("a");
			Assert::AreEqual(*(Variable.rbegin()), 'a');
		}

		// Should set the environment variable: FOR_TEST / `1234567890-=qwertyuiop[]\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:"ZXCVBNM<>?
		TEST_METHOD(TestGetEnvStrictly)
		{
			string Variable = EnvironmentVariableReader::GetEnv("FOR_TEST");

			Assert::IsFalse(Variable.empty());
			Assert::AreEqual(Variable.c_str(), R"(`1234567890-=qwertyuiop[]\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:"ZXCVBNM<>?)");
		}
	};
}
