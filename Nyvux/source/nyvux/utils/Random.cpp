#include "nyvux/utils/Random.h"

nyvux::Random::Random()
{
	Generator = std::mt19937(Rd());
	UniformDistribution = std::uniform_real_distribution<double>(0.0, 1.0);
}

int nyvux::Random::Uniform(const int Start, const int End)
{
	return static_cast<int>(UniformDistribution(Generator) * (End - Start) + Start);
}
