#include <Shoonya.h>

class Sandbox : public Shoonya::Application
{
	public:
		Sandbox() {}
		~Sandbox() {}
};

Shoonya::Application* Shoonya::CreateApplication()
{
	return (new Sandbox());
}