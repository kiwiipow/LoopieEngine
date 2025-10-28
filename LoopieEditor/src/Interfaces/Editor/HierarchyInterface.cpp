#include "HierarchyInterface.h"
#include "Loopie/Core/Log.h"

#include <imgui.h>

namespace Loopie {
	std::shared_ptr<Entity> HierarchyInterface::s_SelectedEntity = nullptr;

	HierarchyInterface::HierarchyInterface() {
		
	}

	void HierarchyInterface::Render() {

		if (ImGui::Begin("Hierarchy")) {
			if (!m_scene) {
				ImGui::End();
				return;
			}
			for (const auto& entity : m_scene->GetRootEntity()->GetChildren())
			{
				DrawEntitySlot(entity);
			}
			
			DrawContextMenu();
			HotKeysSelectedEntiy();
		}
		ImGui::End();
	}

	void HierarchyInterface::SetScene(Scene* scene)
	{
		m_scene = scene;
	}

	void HierarchyInterface::DrawEntitySlot(const std::shared_ptr<Entity>& entity)
	{
		if (!entity)
			return;
		ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_SpanAvailWidth;
		const auto& children = entity->GetChildren();
		bool hasChildren = !children.empty();

		if (!hasChildren)
			flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;
		if (s_SelectedEntity == entity)
			flags |= ImGuiTreeNodeFlags_Selected;

		bool opened = ImGui::TreeNodeEx((void*)(uint64_t)(uint32_t)entity.get(), flags, entity->GetName().c_str());

		if (ImGui::IsItemClicked())
		{
			////Expand To Select Multiple
			s_SelectedEntity = entity;
		}

		DrawEntityContextMenu(entity);

		if (opened && hasChildren)
		{
			for (const auto& child : children)
			{
				DrawEntitySlot(child);
			}
			ImGui::TreePop();
		}

		
		
	}

	void HierarchyInterface::DrawContextMenu()
	{
		if (ImGui::BeginPopupContextWindow("HierarchyBackgroundContext", ImGuiPopupFlags_MouseButtonRight | ImGuiPopupFlags_NoOpenOverItems)) {
			if (ImGui::MenuItem("Create Entity")) {
				m_scene->CreateEntity("Entity");
			}
			ImGui::EndPopup();
		}
	}

	void HierarchyInterface::DrawEntityContextMenu(const std::shared_ptr<Entity> entity)
	{
		if (ImGui::BeginPopupContextItem())
		{

			if (ImGui::MenuItem("Create Entity"))
			{
				m_scene->CreateEntity("Entity", entity);
			}

			/*if (ImGui::MenuItem("Copy"))
			{

			}

			if (ImGui::MenuItem("Cut"))
			{

			}
			
			if (ImGui::MenuItem("Paste"))
			{

			}*/

			if (ImGui::MenuItem("Delete"))
			{
				m_scene->RemoveEntity(entity->GetUUID());
			}

			ImGui::EndPopup();
		}
	}

	void HierarchyInterface::HotKeysSelectedEntiy()
	{
		if (!s_SelectedEntity) {
			return;
		}

		const InputEventManager& input = Application::GetInstance().GetInputEvent();

		if (input.GetKeyStatus(SDL_SCANCODE_DELETE) == KeyState::DOWN) {
			m_scene->RemoveEntity(s_SelectedEntity->GetUUID());
			s_SelectedEntity = nullptr;
		}

		if (input.GetKeyWithModifier(SDL_SCANCODE_C, KeyModifier::CTRL)) {
			/// Copy
		}

		if (input.GetKeyWithModifier(SDL_SCANCODE_V, KeyModifier::CTRL)) {
			/// Paste
		}

		if (input.GetKeyWithModifier(SDL_SCANCODE_X, KeyModifier::CTRL)) {
			/// Cut
		}

	}
}