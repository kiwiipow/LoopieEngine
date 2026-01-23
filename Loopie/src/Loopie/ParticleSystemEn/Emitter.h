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
	enum ParticleType;

	struct ParticleProps
	{
		vec3 Position = vec3(0.0f);
		vec3 Velocity = vec3(0.0f);
		vec3 VelocityVariation = vec3(0.0f);
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
			vec3 m_position;
			bool m_active;

			std::vector<ParticleModule> m_particlePool;
			unsigned int m_poolIndex;

			ParticleProps m_particleProperties;

			/*Texture* m_texture;*/

		public:
			Emitter(unsigned int maxParticles, ParticleType type, vec3 position, unsigned int spawnRate);

			void OnUpdate(float dt);
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

			vec3 GetPosition() const;
			void SetPosition(const vec3& pos);

			ParticleProps& GetEmissionProperties();
			void SetEmisionProperties(const ParticleProps& partProps);
			
			int GetActiveParticles() const;
			bool IsActive() const;

			/*Texture* GetTexture();
			void SetTexture(Texture* tex);*/

	};
}

