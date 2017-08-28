
# include <Siv3D.hpp>
#include <HamFramework.hpp>

#include "Cells\Cells2D.hpp"
#include "Editor.hpp"

using namespace std;

void Main()
{
    ScalableWindow::Setup(1280, 720);
    Window::Resize(800, 450);

    Graphics::SetBackground(Palette::Peachpuff);

    const Font font(30);

    Editor editor;

    
    while (System::Update())
    {

        
        {
            const auto transformer = ScalableWindow::CreateTransformer();

            

        }

        ScalableWindow::DrawBlackBars(Palette::Peachpuff);
    }
}
