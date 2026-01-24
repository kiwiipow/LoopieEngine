#include "ParticleComponent.h"
#include "Loopie/Components/Transform.h"
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
	void ParticleComponent::Init()
	{
		GetTransform()->m_transformNotifier.AddObserver(this);
	}
	void ParticleComponent::Update()
	{

	}
	void ParticleComponent::Reset()
	{

	}

	void ParticleComponent::OnNotify(const TransformNotification& id)
	{
	}

	JsonNode ParticleComponent::Serialize(JsonNode& parent) const
	{
		JsonNode particleObj = parent.CreateObjectField("particlecomponent");
		return particleObj;
	}

	void ParticleComponent::Deserialize(const JsonNode& data)
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