#pragma once
#include "Loopie/Render/VertexArray.h"
#include "Loopie/Resources/Types/Material.h"
#include "Loopie/Render/Shader.h"
#include <vector>
#include <memory>

//#include "Emitter.h"
//#include "Loopie/Math/MathTypes.h"

namespace Loopie
{
	/*class Camera;
	class Shader;*/
	
	//enum ParticleType
	//{
	//	SMOKE_PARTICLE,
	//	FIREWORK_1_PARTICLE,
	//	FIREWORK_2_PARTICLE,
	//	FIREWORK_3_PARTICLE,
	//};
	//struct ParticleProps
	//{
	//	vec2 Position = vec3(0.0f);
	//	vec2 Velocity = vec2(0.0f);
	//	vec2 VelocityVariation = vec2(0.0f);
	//	vec4 ColorBegin = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	//	vec4 ColorEnd = vec4(0.0f, 0.0f, 1.0f, 1.0f);
	//	float SizeBegin = 1.0f;
	//	float SizeEnd = 0.0f;
	//	float SizeVariation = 0.0f;
	//	float LifeTime = 1.0f;
	//	float LifeRemaining = 0.0f;

	//	bool Active = false;
	//};
	class Emitter;
	class ParticleSystem
	{
		private:
			std::vector <Emitter*> m_emittersArray;

			std::shared_ptr<VertexArray> m_quadVAO;
			std::shared_ptr<VertexBuffer> m_quadVBO;
			std::shared_ptr<IndexBuffer> m_quadIBO;
			std::shared_ptr<Material> m_particleMaterial;
			Shader m_particleShader = Shader("assets/shaders/ParticleShader.shader");;

			void InitializeQuad();
			void InitializeMaterial();
			//struct TestParticle
			//{
			//	vec2 Position = vec3(0.0f);
			//	vec2 Velocity = vec2(0.0f);
			//	vec4 ColorBegin = vec4(0.0f);
			//	vec4 ColorEnd = vec4(0.0f);
			//	float Rotation = 0.0f;
			//	float SizeBegin = 1.0f;
			//	float SizeEnd = 0.0f;

			//	float LifeTime = 1.0f;
			//	float LifeRemaining = 0.0f;

			//	bool Active = false;

			//};
			//std::vector<TestParticle> m_particlePool;//contains the max number of particles allowed that get recicled over and over
			//unsigned int m_poolIndex = 0; //index starts in reverse because particles need to be rendered in reverse
			//unsigned int m_maxParticles = 1000;
	/*		float m_particleTimer = 0.0f;*/
			
		public:
			ParticleSystem();
			~ParticleSystem();
	

			void OnUpdate(float dt);//time step
			void OnRender();

			void AddElemToEmitterArray(Emitter* em);
			void DeleteElemFromEmitterArray(Emitter* em);

			std::vector<Emitter*>GetEmitterArray()const;
			std::shared_ptr<VertexArray> GetQuadVAO() const;
			std::shared_ptr<Material> GetMaterial() const;	
			int GetActiveParticles() const;

		/*	ParticleSystem(unsigned int maxParticles = 1000);*/
			/*void Emit(const ParticleProps& particleProps);*/

			//void SetMaxParticles(unsigned int count);
			//int GetMaxParticles() const;
			
			
	};
}