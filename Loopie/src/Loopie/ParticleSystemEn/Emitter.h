#pragma once
#include "Loopie/Resources/Types/Texture.h"
#include <vector>


namespace Loopie 
{
	class ParticleModule;
	enum ParticleType;

	class Emitter
	{
		private:
		private:
			const char* name;
			unsigned int spawnRate;
			unsigned int maxParticles;

			std::vector<ParticleModule*> particleModule;
			Texture* R_Texture;

		public:
			Emitter();
			void SavePartModule();
			void LoadPartModule();
			void AddModule(ParticleType type);

			//getters/setters
			const char* GetName()const;
			void SetName(const char* n);

			unsigned int GetSpawnrate()const;
			void SetSpawnRate(unsigned int spawnR);

			unsigned int GetmaxParticles()const;
			void SetmaxParticles(unsigned int maxPart);

			std::vector<ParticleModule*> GetParticleModule()const;
			void AddElemToParticleModule(ParticleModule& partMod);
	};
}

