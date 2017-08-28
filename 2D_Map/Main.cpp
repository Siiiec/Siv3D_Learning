
# include <Siv3D.hpp>
#include <HamFramework.hpp>

#include "Cells\Cells2D.hpp"
#include "Map2D.hpp"

using namespace std;

void Main()
{
    ScalableWindow::Setup(1280, 720);
    Window::Resize(800, 450);

    Graphics::SetBackground(Palette::Peachpuff);

    const Font font(30);

    Map2D map(20, 20);

    
    while (System::Update())
    {


        {
            const auto transformer = ScalableWindow::CreateTransformer();

            map.draw();

        }

        ScalableWindow::DrawBlackBars(Palette::Peachpuff);
    }
}
