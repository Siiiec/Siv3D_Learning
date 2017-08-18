
# include <Siv3D.hpp>
#include <Siv3DAddon/LeapMotion.hpp>

void Main()
{
	const Font font(30);

    LeapMotion::RegisterAddon();

	while (System::Update())
	{
		font(L"ようこそ、Siv3D の世界へ！").draw();

		Circle(Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });
	}
}
