#pragma once
#include <vector>
#include "Loopie/Math/MathTypes.h"
//#include "Loopie/Components/Component.h"
//#include "Loopie/Events/EventTypes.h"

namespace Loopie
{   
	class EmitterInstance;
	class ParticleSystem;

	struct Particle
	{
		vec3 position;
		quaternion worldRotation;
		float age;
		float lifetime;
		float velocity;
		int spriteIndex;

	};
	class ParticleComponent /*:public Component, public IObserver<TransformNotification>*/
	{/*
		DEFINE_TYPE(ParticleComponent)*/
	private:
		std::vector<EmitterInstance*> emittersVector;
		ParticleSystem* partSystem;
	public:
		ParticleComponent();
		ParticleComponent(ParticleSystem* pSystem);
		void Save();
		void Load();
		void Update();
		void Reset();

		//getters/seters
		std::vector<EmitterInstance*> GetEmittersVector();
		void AddElemToEmitterVector(EmitterInstance* eInstance);
	};
}
