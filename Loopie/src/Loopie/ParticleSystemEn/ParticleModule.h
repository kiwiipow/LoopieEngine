#pragma once
#include <vector>
#include "Loopie/Math/MathTypes.h"
#include "Loopie/Render/VertexArray.h"
#include "Loopie/Resources/Types/Material.h"
#include <memory>

namespace Loopie
{
	
	enum ParticleType
	{
		SMOKE_PARTICLE,
		FIREWORK_1_PARTICLE,
		FIREWORK_2_PARTICLE,
		FIREWORK_3_PARTICLE,
	};

	struct velocityOverLifetime
	{
		vec2 fixedSpeed;
		vec2 minSpeed;
		vec2 maxSpeed;
	};
	struct colorOverLifetime
	{
		vec4 fixedColor;
		vec4 beginColor;
		vec4 endColor;
	};
	struct sizeOverLifetime
	{
		vec2 fixedSize;
		float minSize;
		float maxSize;
	};

	class ParticleModule
	{
		private:
			ParticleType m_partType;
			vec2 m_position;
			float m_rotation;
			velocityOverLifetime m_velocity;
			colorOverLifetime m_color;
			sizeOverLifetime m_size;
			float m_lifetime;
			float m_lifeRemaining;
			bool m_active;

		public:

			ParticleModule();
			void Update(float dt);
			void Render(std::shared_ptr<VertexArray> quadVAO, std::shared_ptr<Material> material);

			/*void Save();
			void Load();*/

			//getters/setters
			ParticleType GetParticleType()const;
			void SetParticleType(ParticleType t);

			vec2 GetPosition() const;
			void SetPosition(const vec2& pos);

			float GetRotation() const;
			void SetRotation(float rot);

			velocityOverLifetime GetVelocityOT()const;
			void SetVelocityOT(velocityOverLifetime vOT);

			colorOverLifetime GetColorOT()const;
			void SetColorOT(colorOverLifetime cOT);

			sizeOverLifetime GetSizeOT()const;
			void SetSizeOT(sizeOverLifetime sOT);

			float GetLifetime() const;
			void SetLifetime(float time);

			float GetLifeRemaining() const;
			void SetLifeRemaining(float L_remain);

	};
}
