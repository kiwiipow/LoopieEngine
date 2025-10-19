#include "Component.h"


#include "Loopie/Scene/Entity.h"
#include "Loopie/Components/Transform.h"

namespace Loopie {
	Component::~Component(){}
	Transform* Component::GetTransform() const
	{
		return GetOwner()->GetTransform();
	}

	const UUID& Component::GetUuid() const
	{
		return m_uuid;
	}

	bool Component::GetIsActive() const
	{
		return m_isActive;
	}

	void Component::SetIsActive(bool active)
	{
		m_isActive = active;
	}

	void Component::SetUuid(const std::string newUuid)
	{
		m_uuid = UUID(newUuid);
	}
}