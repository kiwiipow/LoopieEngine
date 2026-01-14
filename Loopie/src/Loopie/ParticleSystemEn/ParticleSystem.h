#pragma once
#include <vector>
#include "Emitter.h"


namespace Loopie
{
	class ParticleSystem
	{
		private:
			std::vector <Emitter> emittersArray;

		public:
			ParticleSystem()
			{
				
			}
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