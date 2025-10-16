#pragma once 

#include "src/Interfaces/Interface.h"
#include "Loopie/Scene/Scene.h"

namespace Loopie {
	class HierarchyInterface : public Interface {
	public:
		HierarchyInterface();
		~HierarchyInterface() = default;
		void Render() override;

		void SetScene(Scene* scene);

	private:
		void DrawEntitySlot(const std::shared_ptr<Entity>& entity);
	private:
		Scene* m_scene = nullptr;
		std::shared_ptr<Entity> m_selectedEntity;
	};
}