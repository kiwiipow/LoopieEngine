#pragma once
#include <vector>
#include "Loopie/Math/MathTypes.h"
class EmitterInstance;
class ParticleSystem;
namespace Loopie
{
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
		std::vector<EmitterInstance> emittersVector;
		ParticleSystem* partSystem;
	public:
		void Save();
		void Load();
		void Update();
		void Reset();
	};
}
