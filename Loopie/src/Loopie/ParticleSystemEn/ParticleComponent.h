#pragma once
#include <vector>
#include "Loopie/Math/MathTypes.h"

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
	class ParticleComponent
	{
	private:
		std::vector<EmitterInstance*> emittersVector;
		ParticleSystem* partSystem;
	public:
		ParticleComponent();
		void Save();
		void Load();
		void Update();
		void Reset();
	};
}
