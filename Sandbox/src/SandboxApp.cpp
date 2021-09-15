#include <Gear5th.h>

class Sandbox : public Gear5th::Application
{
public:
	Sandbox()
	{

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