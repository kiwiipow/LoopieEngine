#pragma once
#include <vector>
#include "Loopie/Math/MathTypes.h"
#include "Loopie/Components/Component.h"
#include "Loopie/Events/EventTypes.h"

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
	class ParticleComponent :public Component, public IObserver<TransformNotification>
	{
		
	private:
		std::vector<EmitterInstance*> emittersVector;
		ParticleSystem* partSystem;
	public:
		DEFINE_TYPE(ParticleComponent)
		ParticleComponent();
		ParticleComponent(ParticleSystem* pSystem);
		void Save();
		void Load();
		void Init() override; 
		void Update();
		void Reset();

		void OnNotify(const TransformNotification& id) override;

		JsonNode Serialize(JsonNode& parent) const override;
		void Deserialize(const JsonNode& data) override;

		//getters/seters
		std::vector<EmitterInstance*> GetEmittersVector();
		void AddElemToEmitterVector(EmitterInstance* eInstance);

	};
}
