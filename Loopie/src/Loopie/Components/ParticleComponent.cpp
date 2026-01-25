#include "ParticleComponent.h"
#include "Loopie/Components/Transform.h"
#include "Loopie/ParticleSystemEn/ParticleSystem.h"
#include "Loopie/Core/Time.h"
#include "Loopie/Core/Log.h"

//TEMPORARY
#include <iostream>
using namespace std;
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
		//std::cout << "particle update"<<endl;
		Log::Info("particle component is being updated!");
		float dt = (float)Time::GetDeltaTime();
		m_partSystem->OnUpdate(dt);
	}
	void ParticleComponent::Render(Camera* cam)
	{
		m_partSystem->OnRender(cam);
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
		/*particleObj.CreateField<Material>("material", m_partSystem->GetMaterial());
		particleObj.CreateField<float>("fov", m_fov);
		particleObj.CreateField<float>("near_plane", m_nearPlane);
		particleObj.CreateField<float>("far_plane", m_farPlane);
		m_partSystem->GetMaterial();*/
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
		if (m_partSystem != nullptr || emitter != nullptr)
		{
			m_partSystem->AddElemToEmitterArray(emitter);
		}
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