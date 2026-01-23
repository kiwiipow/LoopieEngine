#include "ParticleModule.h"
#include "Loopie/Core/Log.h"
#include "Loopie/Render/Renderer.h"
namespace Loopie
{
	/*void ParticleModule::Save()
	{

	}
	void ParticleModule::Load()
	{

	}*/
	
	ParticleModule::ParticleModule()
	{
		m_partType = SMOKE_PARTICLE;
		m_position = vec2(0,0);
		m_rotation = 0;
		m_velocity.fixedSpeed = vec2(0, 0);
		m_velocity.minSpeed = vec2(0, 0);
		m_velocity.maxSpeed = vec2(0, 0);
		m_color.beginColor = vec4(1, 1, 1, 1);
		m_color.endColor = vec4(1, 1, 1, 1);
		m_size.minSize = 1;
		m_size.maxSize = 1;
		m_lifetime = 1;
		m_lifeRemaining = 0;
		m_active = false;
	}
	
	void ParticleModule::Update(float dt)
	{
		if (m_active)
		{
			return;
		}
		if (m_lifeRemaining <= 0.0f)
		{
			m_active = false;
			return;
		}

		m_lifeRemaining -= dt;
		m_position += m_velocity.fixedSpeed * dt;
		m_rotation += 0.01 * dt;
			
	}
	void ParticleModule::Render(std::shared_ptr<VertexArray> quadVAO, std::shared_ptr<Material> material)
	{
			if (!m_active)
			{
				return;
			}
			
			//interpolations
			float life = m_lifeRemaining / m_lifetime;

			vec4 color;
			color.r = mix(m_color.endColor.r, m_color.beginColor.r, life);
			color.g = mix(m_color.endColor.g, m_color.beginColor.g, life);
			color.b = mix(m_color.endColor.b, m_color.beginColor.b, life);
			color.a = mix(m_color.endColor.a, m_color.beginColor.a, life);

			float size = mix(m_size.maxSize, m_size.minSize, life);

			Log::Info("Particle color: r={}, g={}, b={}, a={}", color.r, color.g, color.b, color.a);
			
			// transform 
			matrix4 transform = translate(matrix4(1.0f), vec3(m_position.x, m_position.y, 0.0f));
			transform = rotate(transform, m_rotation, vec3(0.0f, 0.0f, 1.0f));
			transform = scale(transform, vec3(size, size, 1.0f));

			// Set color USE ENGINE UNIFORM TYPES DONT SET MANUALLY
			UniformValue colorUni;
			colorUni.type = UniformType_vec4;
			colorUni.value = color;
			material->SetShaderVariable("u_Color", colorUni);
			
			//add to renderqueue
			// Render the particle
			//AddParticleRenderItem - > If max capacity reached, flush (this inside AddParticle function), draw and clear pos and color vectors
			Renderer::FlushRenderItem(quadVAO, material, transform);
		
	}
	
	//getters/setters
	ParticleType ParticleModule::GetParticleType()const
	{
		return m_partType;
	}
	void ParticleModule::SetParticleType(ParticleType t)
	{
		m_partType = t;
	}
	vec2 ParticleModule::GetPosition() const
	{
		return m_position;
	}
	void ParticleModule::SetPosition(const vec2& pos)
	{
		m_position = pos;
	}

	float ParticleModule::GetRotation() const
	{
		return m_rotation;
	}
	void ParticleModule::SetRotation(float rot)
	{
		m_rotation = rot;
	}

	velocityOverLifetime ParticleModule::GetVelocityOT()const
	{
		return m_velocity;
	}
	void ParticleModule::SetVelocityOT(velocityOverLifetime vOT)
	{
		m_velocity = vOT;
	}

	colorOverLifetime ParticleModule::GetColorOT()const
	{
		return m_color;
	}
	void ParticleModule::SetColorOT(colorOverLifetime cOT)
	{
		m_color = cOT;
	}

	sizeOverLifetime ParticleModule::GetSizeOT()const
	{
		return m_size;
	}
	void ParticleModule::SetSizeOT(sizeOverLifetime sOT)
	{
		m_size = sOT;
	}

	float ParticleModule::GetLifetime() const
	{
		return m_lifetime;
	}
	void ParticleModule::SetLifetime(float time)
	{
		m_lifetime = time;
		m_lifeRemaining = time;
	}

	float ParticleModule::GetLifeRemaining() const
	{
		return m_lifeRemaining;
	}
	void ParticleModule::SetLifeRemaining(float L_remain) 
	{
		m_lifeRemaining = L_remain;
	}
}
