#include "ParticleComponent.h"

namespace Loopie
{
	ParticleComponent::ParticleComponent()
	{
		partSystem = nullptr;
	}
	ParticleComponent::ParticleComponent(ParticleSystem* pSystem)
	{
		partSystem = pSystem;
	}
	void ParticleComponent::Save()
	{

	}
	void ParticleComponent::Load()
	{

	}
	void ParticleComponent::Update()
	{

	}
	void ParticleComponent::Reset()
	{

	}

	std::vector<EmitterInstance*> ParticleComponent::GetEmittersVector()
	{
		return emittersVector;
	}
	void ParticleComponent::AddElemToEmitterVector(EmitterInstance* eInstance)
	{
		emittersVector.push_back(eInstance);
	}
}