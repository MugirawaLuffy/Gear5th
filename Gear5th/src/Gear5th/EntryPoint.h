#pragma once

#ifdef G5_PLATFORM_WINDOWS

extern Gear5th::Application* Gear5th::CreateApplication();

int main(int argc, char** argv)
{
	printf("Gear5th.dll linked properly, the app is using the builtin EntryPoint provided by Gear5th.dll!");
	
	auto app = Gear5th::CreateApplication();
	app->Run();

	delete app;
}

#endif
