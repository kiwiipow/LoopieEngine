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
		m_position = vec3(0, 0, 0);
		m_active = true;
		m_poolIndex = 0;

		m_particleProperties.Velocity = vec3(0, 0, 0);
		m_particleProperties.VelocityVariation = vec3(1, 1, 0);
		m_particleProperties.ColorBegin = vec4(1,1,1,1);
		m_particleProperties.ColorEnd = vec4(1,1,1,0);
		m_particleProperties.SizeBegin = 1;
		m_particleProperties.SizeEnd = 0;
		m_particleProperties.SizeVariation = 0.5;
		m_particleProperties.LifeTime = 1;

		/*m_texture = nullptr;*/

		m_particlePool.resize(m_maxParticles);
		m_poolIndex = m_maxParticles - 1;
	}

	void Emitter::OnUpdate(float dt)
	{
		//update emiting like in old editor to be able to use particle type later
		for (auto& particle : m_particlePool)
		{
			if (!particle.GetActive())
			{
                continue;
			}
			particle.Update(dt);
		}
		if (m_active && m_spawnRate > 0)
		{
			m_emitterTimer += dt;
			float emissionInterval = 1.0f / m_spawnRate;

			while (m_emitterTimer >= emissionInterval)
			{
				ParticleProps props = m_particleProperties;
				props.Position = m_position;

				Emit(props);
				m_emitterTimer -= emissionInterval;
			}
		}
	}
	void Emitter::OnRender(std::shared_ptr<VertexArray> quadVAO, std::shared_ptr<Material> material)
	{
		for (auto it = m_particlePool.rbegin(); it != m_particlePool.rend(); ++it)
		{
			auto& particle = *it;

			if (!particle.GetActive())
			{
				continue;
			}
				
			particle.Render(quadVAO, material);
		}
	}
	void Emitter::Emit(const ParticleProps& particleProps)
	{
		ParticleModule& particle = m_particlePool[m_poolIndex];
		float twoPi = 6.28318530718f;

		particle.SetActive(true);
		particle.SetPosition(particleProps.Position);
		particle.SetRotation(RandomFloat(0, twoPi));

		// velocity
		vec3 finalVelocity = particleProps.Velocity;
		finalVelocity.x += RandomFloat(-particleProps.VelocityVariation.x * 0.5f, particleProps.VelocityVariation.x * 0.5f);
		finalVelocity.y += RandomFloat(-particleProps.VelocityVariation.y * 0.5f, particleProps.VelocityVariation.y * 0.5f);
		particle.SetVelocity(finalVelocity);

		// colors
		particle.SetColorBegin(particleProps.ColorBegin);
		particle.SetColorEnd(particleProps.ColorEnd);

		// size
		float sizeBegin = particleProps.SizeBegin + RandomFloat(-particleProps.SizeVariation * 0.5f, particleProps.SizeVariation * 0.5f);
		particle.SetSizeBegin(sizeBegin);
		particle.SetSizeEnd(particleProps.SizeEnd);
		
		particle.SetLifetime(particleProps.LifeTime);
		
		m_poolIndex = (m_poolIndex - 1) % m_particlePool.size();
	}
	void Emitter::AddModule(ParticleType type)
	{
		switch (type)
		{
		case Loopie::SMOKE_PARTICLE:

			break;
		case Loopie::FIREWORK_1_PARTICLE:
			break;
		case Loopie::FIREWORK_2_PARTICLE:
			break;
		case Loopie::FIREWORK_3_PARTICLE:
			break;
		default:
			break;
		}
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
		m_particlePool.resize(m_maxParticles);
		m_poolIndex = m_maxParticles - 1;
	}
	vec3 Emitter::GetPosition() const
	{
		return m_position;
	}
	void Emitter::SetPosition(const vec3& pos)
	{
		m_position = pos;
	}
	int Emitter::GetActiveParticles() const
	{
		int count = 0;
		for (const auto& particle : m_particlePool)
		{
			if (particle.GetActive())
			{
				count++;
			}
				
		}
		return count;
	}
	bool Emitter::IsActive() const
	{
		return m_active;
	}
	void Emitter::SetEmisionProperties(const ParticleProps& partProps)
	{
		m_particleProperties = partProps;
	}
	ParticleProps& Emitter::GetEmissionProperties()
	{ 
		return m_particleProperties;
	}
}