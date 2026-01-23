#pragma once
#include "ParticleModule.h"
#include "Loopie/Render/VertexArray.h"
#include "Loopie/Resources/Types/Material.h"
#include "Loopie/Resources/Types/Texture.h"

#include "Loopie/Math/MathTypes.h"
#include <vector>
#include <memory>

namespace Loopie 
{
	/*enum ParticleType
	{
		SMOKE_PARTICLE,
		FIREWORK_1_PARTICLE,
		FIREWORK_2_PARTICLE,
		FIREWORK_3_PARTICLE,
	};*/
	struct ParticleProps
	{
		vec2 Velocity = vec2(0.0f);
		vec2 VelocityVariation = vec2(0.0f);
		vec4 ColorBegin = vec4(1.0f, 0.0f, 0.0f, 1.0f);
		vec4 ColorEnd = vec4(0.0f, 0.0f, 1.0f, 1.0f);
		float SizeBegin = 1.0f;
		float SizeEnd = 0.0f;
		float SizeVariation = 0.0f;
		float LifeTime = 1.0f;
		
	};
	class Emitter
	{
		private:
			const char* m_name;
			unsigned int m_spawnRate;
			unsigned int m_maxParticles;
			float m_emitterTimer;
			vec2 m_position;
			bool m_active;

			std::vector<ParticleModule> m_particlePool;
			unsigned int m_poolIndex;

			ParticleProps* m_particleProperties;

			Texture* m_texture;

		/*	struct TestParticle
			{
				vec2 Position = vec3(0.0f);
				vec2 Velocity = vec2(0.0f);
				vec4 ColorBegin = vec4(0.0f);
				vec4 ColorEnd = vec4(0.0f);
				float Rotation = 0.0f;
				float SizeBegin = 1.0f;
				float SizeEnd = 0.0f;

				float LifeTime = 1.0f;
				float LifeRemaining = 0.0f;

				bool Active = false;

			};*/
		
		public:
			Emitter();
			Emitter(unsigned int maxParticles);

			void OnUpdate(float deltaTime);
			void OnRender(std::shared_ptr<VertexArray> quadVAO, std::shared_ptr<Material> material);
			void Emit(const ParticleProps& particleProps);

			void AddModule(ParticleType type);
			
			//getters/setters
			const char* GetName()const;
			void SetName(const char* n);

			unsigned int GetSpawnrate()const;
			void SetSpawnRate(unsigned int spawnR);

			unsigned int GetmaxParticles()const;
			void SetmaxParticles(unsigned int maxPart);

			vec2 GetPosition() const;
			void SetPosition(const vec2& pos);

			void SetEmisionProperties(ParticleProps* partProps);
			
			int GetActiveParticles() const;
			bool IsActive() const;

			/*
			void SavePartModule();
			void LoadPartModule();*/
	};
}

