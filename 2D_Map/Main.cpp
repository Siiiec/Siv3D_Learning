
# include <Siv3D.hpp>
#include <HamFramework.hpp>

#include "Cells\Cells2D.hpp"
#include "Editor.hpp"
#include "Map2D.hpp"


void Main()
{
    Window::SetBaseSize(1280, 720);
    ScalableWindow::Setup(1280, 720);
    Window::Resize(800, 450);

    Graphics::SetBackground(Palette::Peachpuff);

    const Font font(30);

    Map2D map {10, 20};
        
    while (System::Update())
    {
        {
            const auto transformer = ScalableWindow::CreateTransformer();
            map.update();
            map.draw();
            

        }

        ScalableWindow::DrawBlackBars(Palette::Black);
    }
}