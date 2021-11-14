#pragma once

#include "KDF/Layer.h"


namespace KDF {

	class KDF_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();

		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		float m_time = 0.0f;
	};

}