#include <Gear5th.h>

class ExampleLayer : public Gear5th::Layer
{
public: 
	ExampleLayer()
		: Layer("Example")
	{}

	void OnUpdate() override
	{
		G5_INFO("ExampleLayer::OnUpdate()");
	}

	void OnEvent(Gear5th::Event& event) override
	{
		G5_TRACE("{0}", event);
	}
};

class Sandbox : public Gear5th::Application
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

Gear5th::Application* Gear5th::CreateApplication()
{
	return new Sandbox();	//explicitly allocated on the heap because it's a
							//			big chungus app and I want total control over it's memory
}