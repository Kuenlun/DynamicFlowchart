#pragma once

#include "KDF/Layer.h"

#include "KDF/Events/ApplicationEvent.h"
#include "KDF/Events/KeyEvent.h"
#include "KDF/Events/MouseEvent.h"


namespace KDF {

	class KDF_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_time = 0.0f;
	};

}