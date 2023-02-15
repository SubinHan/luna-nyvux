#include "pch.h"
#include "CppUnitTest.h"
#include "../Nyvux/include/nyvux/utils/Random.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NyvuxTest
{
	using namespace nyvux;
	using namespace std;

	TEST_CLASS(RandomTest)
	{
	public:
		TEST_METHOD(UniformTest)
		{
			Random Rand{};

			constexpr int NUM_TRIES = 10'000'000;
			constexpr int ARRAY_SIZE = 5;
			constexpr int THRESHOLD = 10'000;
			constexpr int IDEAL_RESULT = NUM_TRIES / ARRAY_SIZE;

			int Array[ARRAY_SIZE];

			for (int i = 0; i < ARRAY_SIZE; i++)
				Array[i] = 0;

			for(int i = 0; i < NUM_TRIES; i++)
			{
				Array[Rand.Uniform(0, 5)]++;
			}

			for(int i = 0; i < ARRAY_SIZE; i++)
			{
				if (!(IDEAL_RESULT - THRESHOLD < Array[i] && Array[i] < IDEAL_RESULT + THRESHOLD))
					Assert::Fail();
			}

		}
	};
}
