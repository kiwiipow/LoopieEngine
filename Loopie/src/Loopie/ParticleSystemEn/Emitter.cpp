#include "Emitter.h"
#include "Loopie/ParticleSystemEn/ParticleModule.h"
namespace Loopie
{
	//rand number generator
	float RandomFloat(float min, float max)
	{
		return min + ((float)rand() / (float)RAND_MAX) * (max - min);
	}

	Emitter::Emitter(unsigned int maxParticles)
	{
		m_name = "DefaultName";
		m_spawnRate = 10;
		m_maxParticles = maxParticles;
		m_emitterTimer = 0;
		m_position = vec2(0, 0);
		m_active = true;
		m_poolIndex = 0;

		m_particleProperties->Velocity = vec2(0,0);
		m_particleProperties->VelocityVariation = vec2(1,1);
		m_particleProperties->ColorBegin = vec4(1,1,1,1);
		m_particleProperties->ColorEnd = vec4(1,1,1,0);
		m_particleProperties->SizeBegin = 1;
		m_particleProperties->SizeEnd = 0;
		m_particleProperties->SizeVariation = 0.5;
		m_particleProperties->LifeTime = 1;

		m_texture = nullptr;

		m_particlePool.resize(m_maxParticles);
		m_poolIndex = m_maxParticles - 1;
	}

	void Emitter::OnUpdate(float deltaTime)
	{
		//loop pool to call update on particles

		//update emiting like in old editor to be able to use particle type later
		//m_particleSystem->OnUpdate(dt);

		//m_particleTimer += dt;
		//if (m_particleTimer >= 0.015f)
		//{
		//	m_particleTimer = 0.0f;

		//	//should add prop templates for smoke and firework
		//	Loopie::ParticleProps props;
		//	props.Position = vec2(0.0f, 7.0f);
		//	props.Velocity = vec2(0.0f, 2.0f);
		//	props.VelocityVariation = vec2(1.0f, 0.5f);
		//	props.ColorBegin = vec4(0.1f, 0.1f, 0.1f, 1.0f);
		//	props.ColorEnd = vec4(1.0f, 1.0f, 1.0f, 0.0f);
		//	props.SizeBegin = 0.5f;
		//	props.SizeEnd = 0.0f;
		//	props.SizeVariation = 0.2f;
		//	props.LifeTime = 1.0f;

		//	m_particleSystem->Emit(props);
		//}

	}
	void Emitter::OnRender(std::shared_ptr<VertexArray> quadVAO, std::shared_ptr<Material> material)
	{
	//add the reverse order loop through particle pool of the onredner in the system
	}
	void Emitter::Emit(const ParticleProps& particleProps)
	{
		//add emit code from system and fix variables
	}
	/*void Emitter::SavePartModule()
	{

	}
	void Emitter::LoadPartModule()
	{

	}*/
	void Emitter::AddModule(ParticleType type)
	{

	}


	const char* Emitter::GetName()const
	{
		return m_name;
	}
	void Emitter::SetName(const char* n)
	{
		m_name = n;
	}

	unsigned int Emitter::GetSpawnrate()const
	{
		return m_spawnRate;
	}
	void Emitter::SetSpawnRate(unsigned int spawnR)
	{
		m_spawnRate = spawnR;
	}

	unsigned int Emitter::GetmaxParticles()const
	{
		return m_maxParticles;
	}
	void Emitter::SetmaxParticles(unsigned int maxPart)
	{
		m_maxParticles = maxPart;
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