#pragma once
#include <vector>
#include "Loopie/Math/MathTypes.h"
#include "Loopie/Components/Component.h"
#include "Loopie/Events/EventTypes.h"

namespace Loopie
{   
	
	class ParticleSystem;

	//struct Particle
	//{
	//	vec3 position;
	//	quaternion worldRotation;
	//	float age;
	//	float lifetime;
	//	float velocity;
	//	int spriteIndex;

	//};
	class ParticleComponent : public Component
	{
	DEFINE_TYPE(ParticleComponent)
	private:
		/*std::vector<EmitterInstance*> emittersVector;*/
		ParticleSystem* m_partSystem;
	public:
		ParticleComponent();
		ParticleComponent(ParticleSystem* pSystem);

		void Init() override; 

		void Save();
		void Load();
		void Update();
		void Reset();

		//getters/seters
		ParticleSystem* GetParticleSystem();
		void SetParticleSystem(ParticleSystem* p_system);
		/*std::vector<EmitterInstance*> GetEmittersVector();
		void AddElemToEmitterVector(EmitterInstance* eInstance);*/
	};
}
