#include "ParticleComponent.h"
#include "Loopie/Components/Transform.h"
#include "Loopie/ParticleSystemEn/ParticleSystem.h"
#include "Loopie/Core/Time.h"
#include "Loopie/Core/Log.h"
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
		Log::Info("particle component is being updated!");
		float dt = (float)Time::GetDeltaTime();
		m_partSystem->OnUpdate(dt);
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
	std::vector<Emitter*> ParticleComponent::GetEmittersVector()
	{
		return m_partSystem->GetEmitterArray();
	}
	void ParticleComponent::AddElemToEmitterVector(Emitter* emitter)
	{
		m_partSystem->AddElemToEmitterArray(emitter);
	}
	ParticleSystem* ParticleComponent::GetParticleSystem()
	{
		return m_partSystem;
	}
	void ParticleComponent::SetParticleSystem(ParticleSystem* pSystem)
	{
		m_partSystem = pSystem;
	}
}