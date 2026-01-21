#pragma once
#include "ParticleSystem.h"
#include "Loopie/Core/Log.h"
#include "Loopie/Render/Renderer.h"
#include "Loopie/Resources/AssetRegistry.h"
#include "Loopie/Resources/ResourceManager.h"
#include <random>

namespace Loopie 
{
	// Random number generator
	float RandomFloat(float min, float max)
	{
		return min + ((float)rand() / (float)RAND_MAX) * (max - min);
	}


	ParticleSystem::ParticleSystem(unsigned int maxParticles): m_maxParticles(maxParticles)
	{
		m_particlePool.resize(m_maxParticles);
		m_poolIndex = m_maxParticles - 1;

		InitializeQuad();
		InitializeMaterial();
	}
	

	void ParticleSystem::InitializeQuad() 
	{
		
		float vertices[] = 
		{
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
		};

		unsigned int indices[] = 
		{
			0, 1, 2,
			2, 3, 0
		};

		m_quadVBO = std::make_shared<VertexBuffer>(vertices, sizeof(vertices));
		m_quadIBO = std::make_shared<IndexBuffer>(indices, 6);

		BufferLayout layout;
		layout.AddLayoutElement(0, GLVariableType::FLOAT, 3, "Position");
		m_quadVBO->SetLayout(layout);

		m_quadVAO = std::make_shared<VertexArray>();
		m_quadVAO->AddBuffer(m_quadVBO.get(), m_quadIBO.get());
	}
	void ParticleSystem::InitializeMaterial() 
	{
		
		Metadata& metadata = AssetRegistry::GetOrCreateMetadata("../LoopieEditor/assets/materials/ParticleMaterial.mat");//if locations change this needs to change
		m_particleMaterial = ResourceManager::GetMaterial(metadata);

		//THIS LINE SHOULD BE ENAMBLED BUT  MAKES IT NOT WORK I DONT UNDERSTAND 
		m_particleMaterial.get()->SetShader("../LoopieEditor/assets/shaders/ParticleShader.shader");
		
		if (!m_particleMaterial)
		{
			Log::Error("Failed to load particle material!");
		}
		
	}

	void ParticleSystem::OnUpdate(float deltaTime)
	{
		for (auto& particle : m_particlePool) 
		{
			if (!particle.Active)
			{
				continue;
			}
			if (particle.LifeRemaining <= 0.0f) 
			{
				particle.Active = false;
				continue;
			}

			particle.LifeRemaining -= deltaTime;
			particle.Position += particle.Velocity * deltaTime;
			particle.Rotation += 0.01 * deltaTime;
		}
	}
	void ParticleSystem::Emit(const ParticleProps& particleProps)
	{
		TestParticle& particle = m_particlePool[m_poolIndex];
		float twoPi = 6.28318530718f;

		particle.Active = true;
		particle.Position = particleProps.Position;
		particle.Rotation = RandomFloat(0, twoPi) ;

	
		particle.Velocity = particleProps.Velocity;
		particle.Velocity.x += RandomFloat(-particleProps.VelocityVariation.x * 0.5f, particleProps.VelocityVariation.x * 0.5f);
		particle.Velocity.y += RandomFloat(-particleProps.VelocityVariation.y * 0.5f, particleProps.VelocityVariation.y * 0.5f);

		
		particle.ColorBegin = particleProps.ColorBegin;
		particle.ColorEnd = particleProps.ColorEnd;

		
		particle.SizeBegin = particleProps.SizeBegin + RandomFloat(-particleProps.SizeVariation * 0.5f, particleProps.SizeVariation * 0.5f);
		particle.SizeEnd = particleProps.SizeEnd;

		
		particle.LifeTime = particleProps.LifeTime;
		particle.LifeRemaining = particleProps.LifeTime;

		// Update index 
		m_poolIndex = (m_poolIndex - 1) % m_particlePool.size();
	}
	void ParticleSystem::OnRender()
	{
		if (!m_quadVAO || !m_particleMaterial)
		{
			return;
		}
			

		// Render particles in reverse order for proper blending
		for (auto it = m_particlePool.rbegin(); it != m_particlePool.rend(); ++it) 
		{
			auto& particle = *it;

			if (!particle.Active)
			{
				continue;
			}
			
			//interpolations
			float life = particle.LifeRemaining / particle.LifeTime;

			vec4 color;
			color.r = glm::mix(particle.ColorEnd.r, particle.ColorBegin.r, life);
			color.g = glm::mix(particle.ColorEnd.g, particle.ColorBegin.g, life);
			color.b = glm::mix(particle.ColorEnd.b, particle.ColorBegin.b, life);
			color.a = glm::mix(particle.ColorEnd.a, particle.ColorBegin.a, life);

			float size = glm::mix(particle.SizeEnd, particle.SizeBegin, life);

			// transform matrix
			matrix4 transform = translate(matrix4(1.0f), vec3(particle.Position.x, particle.Position.y, 0.0f));
			transform = rotate(transform, particle.Rotation, vec3(0.0f, 0.0f, 1.0f));
			transform = scale(transform, vec3(size, size, 1.0f));

			// Set material color 
			m_particleMaterial->Bind();
			m_particleMaterial->GetShader().SetUniformVec4("u_Color", color);

			// Render the particle
			Renderer::FlushRenderItem(m_quadVAO, m_particleMaterial, transform);
		}
	}

	void ParticleSystem::SetMaxParticles(unsigned int count) 
	{
		m_maxParticles = count;
		m_particlePool.resize(m_maxParticles);
		m_poolIndex = m_maxParticles - 1;
	}
	int ParticleSystem::GetMaxParticles() const
	{
		return m_maxParticles; 
	}
	int ParticleSystem::GetActiveParticles() const 
	{
		int count = 0;
		for (const auto& particle : m_particlePool) 
		{
			if (particle.Active)
			{
				count++;

			}	
		}
		return count;
	}
	std::vector<Emitter> ParticleSystem::GetEmitterArray()const
	{
		return m_emittersArray;
	}
	void ParticleSystem::AddElemToEmitterArray(Emitter em)
	{
		m_emittersArray.push_back(em);
	}

	
}