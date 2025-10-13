#include "Transform.h"
#include "Loopie/Core/Log.h"

namespace Loopie
{
	Transform::Transform(const vec3& position, const quaternion& rotation, const vec3& scale) : m_position(position), m_rotation(rotation), m_scale(scale){}

    matrix4 Transform::GetTransformMatrix() const
	{
		matrix4 trsMatrix = glm::mat4(1.0f);

		trsMatrix = glm::translate(trsMatrix, m_position);

		glm::quat normalizedRotation = glm::normalize(m_rotation);

		trsMatrix *= glm::mat4_cast(normalizedRotation);

		trsMatrix *= glm::scale(trsMatrix, m_scale);

		return trsMatrix;
	}




	vec3 Transform::GetEulerAnglesRad() const
	{ return glm::eulerAngles(m_rotation); }

	vec3 Transform::GetEulerAnglesDeg() const
	{ return glm::degrees(GetEulerAnglesRad()); }
	
	void Transform::SetEulerAnglesRad(const vec3& rotation)
	{
		m_rotation = glm::quat(rotation);
	}

	void Transform::SetEulerAnglesDeg(const vec3& rotation)
	{
		SetEulerAnglesRad(glm::radians(rotation));
	}
}