#include "Resource.h"
#include "Loopie/Resources/ResourceManager.h"

namespace Loopie {
	Resource::~Resource() = default;

	void Resource::DecrementReferenceCount()
	{
		if (m_referenceCount > 0)
			m_referenceCount--;
		
		if(m_referenceCount == 0)
		{
			ResourceManager::RemoveResource(*this);
		}
			
	}
}