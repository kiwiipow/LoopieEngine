#pragma once
#include <vector>

struct Particle;
class ParticleComponent;

namespace Loopie
{
	class EmitterInstance
	{
		private:
			std::vector<Particle> particlesVector;
			ParticleComponent* owner;

		public:
			EmitterInstance();
			void Init();
			void UpdateModules();
			void DrawParticles();


	};
}