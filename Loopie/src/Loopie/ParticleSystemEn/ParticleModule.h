#pragma once
#include <vector>
#include "Loopie/Math/MathTypes.h"
class EmitterInstance;

namespace Loopie
{
	enum ParticleTypeEnum
	{
		SMOKE_PARTICLE,
		FIREWORK_1_PARTICLE,
		FIREWORK_2_PARTICLE,
		FIREWORK_3_PARTICLE,
	};

	struct velocityOverLifetime
	{
		float minSpeed;
		float maxSpeed;
	};
	struct colorOverLifetime
	{
		vec3 sourceColor;
		vec3 destinationColor;
	};
	struct sizeOverLifetime
	{
		vec2 minSize;
		vec2 maxSize;
	};

	class ParticleModule
	{
		private:

			ParticleTypeEnum partType;
			velocityOverLifetime velocityOT;
			colorOverLifetime colorOT;
			sizeOverLifetime sizeOT;

		public:

			ParticleModule();
			void Spawn(EmitterInstance* emitter);
			void Update(EmitterInstance* emitter);

			void Save();
			void Load();

			//getters/setters
			ParticleTypeEnum GetParticleType()const;
			void SetParticleType(ParticleTypeEnum t);

			velocityOverLifetime GetVelocityOT()const;
			void SetVelocityOT(velocityOverLifetime vOT);

			colorOverLifetime GetColorOT()const;
			void SetColorOT(colorOverLifetime cOT);

			sizeOverLifetime GetSizeOT()const;
			void SetSizeOT(sizeOverLifetime sOT);
	};
}
