#pragma once
#include <random>

namespace nyvux
{
	class Random
	{
	public:
		Random();

		int Uniform(const int Start, const int End);

	private:
		std::random_device Rd;
		std::mt19937 Generator;
		std::uniform_real_distribution<double> UniformDistribution;
	};
}
