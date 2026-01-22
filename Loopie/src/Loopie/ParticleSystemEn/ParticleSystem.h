#pragma once
#include "Emitter.h"
#include "Loopie/Render/VertexArray.h"
#include "Loopie/Resources/Types/Material.h"
#include <vector>
#include <memory>

#include "Loopie/Math/MathTypes.h"

namespace Loopie
{
	class Camera;
	class Shader;
	struct ParticleProps
	{
		vec2 Position = vec3(0.0f);
		vec2 Velocity = vec2(0.0f);
		vec2 VelocityVariation = vec2(0.0f);
		vec4 ColorBegin = vec4(1.0f, 0.0f, 0.0f, 1.0f);
		vec4 ColorEnd = vec4(0.0f, 0.0f, 1.0f, 1.0f);
		float SizeBegin = 1.0f;
		float SizeEnd = 0.0f;
		float SizeVariation = 0.0f;
		float LifeTime = 1.0f;
		float LifeRemaining = 0.0f;

		bool Active = false;
	};
	class ParticleSystem
	{
		private:
			std::vector <Emitter> m_emittersArray;

			struct TestParticle
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

			};

			void InitializeQuad();
			void InitializeMaterial();

			std::vector<TestParticle> m_particlePool;//contains the max number of particles allowed that get recicled over and over
			unsigned int m_poolIndex = 0; //index starts in reverse because particles need to be rendered in reverse
			unsigned int m_maxParticles = 1000;


			//harcode quad
			std::shared_ptr<VertexArray> m_quadVAO;
			std::shared_ptr<VertexBuffer> m_quadVBO;
			std::shared_ptr<IndexBuffer> m_quadIBO;
			std::shared_ptr<Material> m_particleMaterial;
			
		public:
			ParticleSystem(unsigned int maxParticles = 1000);
		

			void OnUpdate(float dt);//time step
			void OnRender();
			void Emit(const ParticleProps& particleProps);

			void SetMaxParticles(unsigned int count);
			int GetMaxParticles() const;
			int GetActiveParticles() const;

			//setters/getters
			std::vector<Emitter>GetEmitterArray()const;
			void AddElemToEmitterArray(Emitter em);
	};
}