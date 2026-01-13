#include "ParticleModule.h"

namespace Loopie
{
	ParticleModule::ParticleModule()
	{

	}
	void ParticleModule::Spawn(EmitterInstance* emitter)
	{

	}
	void ParticleModule::Update(EmitterInstance* emitter)
	{

	}
	void ParticleModule::Save()
	{

	}
	void ParticleModule::Load()
	{

	}

	//getters/setters
	ParticleType ParticleModule::GetParticleType()const
	{
		return partType;
	}
	void ParticleModule::SetParticleType(ParticleType t)
	{
		partType = t;
	}

	velocityOverLifetime ParticleModule::GetVelocityOT()const
	{
		return velocityOT;
	}
	void ParticleModule::SetVelocityOT(velocityOverLifetime vOT)
	{
		velocityOT = vOT;
	}

	colorOverLifetime ParticleModule::GetColorOT()const
	{
		return colorOT;
	}
	void ParticleModule::SetColorOT(colorOverLifetime cOT)
	{
		colorOT = cOT;
	}

	sizeOverLifetime ParticleModule::GetSizeOT()const
	{
		return sizeOT;
	}
	void ParticleModule::SetSizeOT(sizeOverLifetime sOT)
	{
		sizeOT = sOT;
	}
}
