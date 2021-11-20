#include <KDF.h>


class ExampleLayer : public KDF::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
	{
		m_VertexArray.reset(KDF::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			 0.0f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f
		};

		std::shared_ptr<KDF::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(KDF::VertexBuffer::Create(vertices, sizeof(vertices)));

		KDF::BufferLayout layout = {
			{ KDF::ShaderDataType::Float3, "a_Position" },
			{ KDF::ShaderDataType::Float4, "a_Color" }
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);


		// Index Buffer
		uint32_t indices[3] = { 0, 1, 2 };
		std::shared_ptr<KDF::IndexBuffer> indexBuffer;
		indexBuffer.reset(KDF::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(KDF::VertexArray::Create());

		float squareVertices[3 * 4] = {
			-0.75f, -0.75f, 0.0f,
			 0.75f, -0.75f, 0.0f,
			 0.75f,  0.75f, 0.0f,
			-0.75f,  0.75f, 0.0f
		};

		std::shared_ptr<KDF::VertexBuffer> squareVB;
		squareVB.reset(KDF::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
				{ KDF::ShaderDataType::Float3, "a_Position" }
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		// Index Buffer
		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<KDF::IndexBuffer> squareIB;
		squareIB.reset(KDF::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		// Shader
		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			out vec4 v_Color;
			
			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;
			
			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader.reset(new KDF::Shader(vertexSrc, fragmentSrc));



		std::string blueShaderVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			
			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}
		)";

		std::string blueShaderFragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			
			void main()
			{
				color = vec4(0.2, 0.3, 0.8, 1.0);
			}
		)";

		m_BlueShader.reset(new KDF::Shader(blueShaderVertexSrc, blueShaderFragmentSrc));
	}

	void OnUpdate() override
	{
		if (KDF::Input::IsKeyPressed(KDF_KEY_LEFT))
			m_CameraPosition.x -= m_CameraMoveSpeed;

		if (KDF::Input::IsKeyPressed(KDF_KEY_RIGHT))
			m_CameraPosition.x += m_CameraMoveSpeed;

		if (KDF::Input::IsKeyPressed(KDF_KEY_DOWN))
			m_CameraPosition.y -= m_CameraMoveSpeed;

		if (KDF::Input::IsKeyPressed(KDF_KEY_UP))
			m_CameraPosition.y += m_CameraMoveSpeed;

		if (KDF::Input::IsKeyPressed(KDF_KEY_A))
			m_CameraRotation += m_CameraRotationSpeed;
		
		if (KDF::Input::IsKeyPressed(KDF_KEY_D))
			m_CameraRotation -= m_CameraRotationSpeed;

		KDF::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		KDF::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		KDF::Renderer::BeginScene(m_Camera);

		KDF::Renderer::Submit(m_BlueShader, m_SquareVA);
		KDF::Renderer::Submit(m_Shader, m_VertexArray);

		KDF::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
			
	}

	void OnEvent(KDF::Event& event) override
	{
	}

private:
	std::shared_ptr<KDF::Shader> m_Shader;
	std::shared_ptr<KDF::VertexArray> m_VertexArray;

	std::shared_ptr<KDF::Shader> m_BlueShader;
	std::shared_ptr<KDF::VertexArray> m_SquareVA;

	KDF::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 0.01f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 1.0f;
	
};


class Sandbox : public KDF::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{
	}
};

KDF::Application* KDF::CreateApplication()
{
	return new Sandbox();
}