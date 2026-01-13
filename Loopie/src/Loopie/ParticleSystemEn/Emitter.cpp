#include "Emitter.h"
#include "Loopie/ParticleSystemEn/ParticleModule.h"
namespace Loopie
{
	Emitter::Emitter()
	{

	}
	void Emitter::SavePartModule()
	{

	}
	void Emitter::LoadPartModule()
	{

	}
	void Emitter::AddModule(ParticleTypeEnum type)
	{

	}


	const char* Emitter::GetName()const
	{
		return name;
	}
	void Emitter::SetName(const char* n)
	{
		name = n;
	}

	unsigned int Emitter::GetSpawnrate()const
	{
		return spawnRate;
	}
	void Emitter::SetSpawnRate(unsigned int spawnR)
	{
		spawnRate = spawnR;
	}

	unsigned int Emitter::GetmaxParticles()const
	{
		return maxParticles;
	}
	void Emitter::SetmaxParticles(unsigned int maxPart)
	{
		maxParticles = maxPart;
	}

	std::vector<ParticleModule*> Emitter::GetParticleModule()const
	{
		return particleModule;
	}
	void Emitter::AddElemToParticleModule(ParticleModule& partMod)
	{
		particleModule.push_back(&partMod);
	}
}