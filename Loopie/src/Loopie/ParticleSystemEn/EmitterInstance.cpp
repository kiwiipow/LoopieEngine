#include "EmitterInstance.h"
namespace Loopie
{
	EmitterInstance::EmitterInstance()
	{

	}
	void EmitterInstance::Init()
	{

	}
	void EmitterInstance::UpdateModules()
	{

	}
	void EmitterInstance::DrawParticles()
	{

	}


	ParticleComponent* EmitterInstance::GetParticleComponent()
	{
		return owner;
	}
	void EmitterInstance::SetParticleComponent(ParticleComponent* pc)
	{
		owner = pc;
	}
}
