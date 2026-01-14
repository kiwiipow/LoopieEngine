#pragma once
#include <vector>
#include "ParticleComponent.h"
namespace Loopie
{
	class ParticleComponent;

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

			//getters/setters
			ParticleComponent* GetParticleComponent();
			void SetParticleComponent(ParticleComponent* pc);


	};
}