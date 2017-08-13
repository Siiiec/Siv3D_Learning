
# include <Siv3D.hpp>
#include <HamFramework.hpp>

void Main()
{
    ScalableWindow::Setup(1280, 720);
    
    Window::Resize(800, 450);

    const Font font(30);


    GUIStyle style = GUIStyle::Default;
    style.movable = true;
    style.font = font;

    GUI gui1(style);
    gui1.setTitle(L"1");
    gui1.add(L"text", GUIText::Create(L"", 300));

    GUI gui2(style);
    gui2.setTitle(L"2");
    gui2.add(L"text", GUIText::Create(L"", 300));
    gui2.setCenter({200.0, 0.0});


    GUI gui3(style);
    gui3.setTitle(L"3");
    gui3.add(L"text", GUIText::Create(L"", 300));


    GUI gui4(style);
    gui4.setTitle(L"4");
    gui4.add(L"text", GUIText::Create(L"", 300));


    while (System::Update())
    {

        {
            const auto transformer = ScalableWindow::CreateTransformer();

            font(L"ようこそ、Siv3D の世界へ！").draw();

            Circle(Mouse::Pos(), 50).draw({255, 0, 0, 127});

        }

        ScalableWindow::DrawBlackBars(HSV(40, 0.2, 0.9));
    }
}
