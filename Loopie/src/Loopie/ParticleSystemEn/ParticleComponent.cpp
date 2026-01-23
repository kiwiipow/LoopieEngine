#include "ParticleComponent.h"

namespace Loopie
{
	ParticleComponent::ParticleComponent()
	{
		m_partSystem = nullptr;
	}
	ParticleComponent::ParticleComponent(ParticleSystem* pSystem)
	{
		m_partSystem = pSystem;
	}
	void ParticleComponent::Update()
	{

	}
	void ParticleComponent::Reset()
	{

	}
	ParticleSystem* ParticleComponent::GetParticleSystem()
	{
		return m_partSystem;
	}
	void ParticleComponent::SetParticleSystem(ParticleSystem* p_system)
	{
		m_partSystem = p_system;
	}
	/*std::vector<EmitterInstance*> ParticleComponent::GetEmittersVector()
	{
		return emittersVector;
	}
	void ParticleComponent::AddElemToEmitterVector(EmitterInstance* eInstance)
	{
		emittersVector.push_back(eInstance);
	}*/
}