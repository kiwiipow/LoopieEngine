#pragma once
#include <vector>
#include "Emitter.h"


namespace Loopie
{
	class Camera;
	class Shader;
	struct ParticleProps
	{
		glm::vec2 Position;
		glm::vec2 Velocity, VelocityVariation;
		glm::vec4 ColorBegin, ColorEnd;
		float SizeBegin, SizeEnd, SizeVariation;
		float LifeTime = 1.0f;
	};
	class ParticleSystem
	{
		private:
			std::vector <Emitter> emittersArray;

			struct TestParticle
			{
				glm::vec2 Position;
				glm::vec2 Velocity;
				glm::vec4 ColorBegin, ColorEnd;
				float Rotation = 0.0f;
				float SizeBegin, SizeEnd;

				float LifeTime = 1.0f;
				float LifeRemaining = 0.0f;

				bool Active = false;

			};
			std::vector<TestParticle> m_ParticlePool;//contains the max number of particles allowed that get recicled over and over
			uint32_t m_PoolIndex = 999; //index starts in reverse because particles need to be rendered in reverse

			GLuint m_QuadVA = 0;
			std::unique_ptr<Shader> m_ParticleShader;
			GLint m_ParticleShaderViewProj, m_ParticleShaderTransform, m_ParticleShaderColor;
		public:
			ParticleSystem()
			{
				
			}

			void OnUpdate(float ts);//time step
			void OnRender(Camera camera);
			void Emit(const ParticleProps& particleProps);

			//setters/getters
			std::vector<Emitter>GetEmitterArray()const
			{
				return emittersArray;
			}
			void AddElemToEmitterArray(Emitter em)
			{
				emittersArray.push_back(em);
			}
	};
}