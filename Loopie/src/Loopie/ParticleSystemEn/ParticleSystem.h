#pragma once
#include <vector>

class Emitter;

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
			void AddElemToEmitterArray(Emitter em)const
			{
				emittersArray.push_back(em);
			}
	};
}