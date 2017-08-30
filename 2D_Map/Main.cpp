
# include <Siv3D.hpp>
#include <HamFramework.hpp>

#include "Cells\Cells2D.hpp"
#include "Editor.hpp"
#include "Map2D.hpp"


void ConsoleIO()
{
    using Cells::Cells2D;
    using namespace std;

    Console::Open();
    
    auto cells {Cells2D<int>(5, 10)};

    for (int i = 0; i < cells.size(); ++i)
    {
        cells[i] = i;

    }

    //cout.width(3);

    cout << "------range-based loop-------\n";

    for (const auto& c : cells)
    {
        cout << c << " \n";
    }

    cout << "-------２重ループ-------\n";
    
    for (int r = 0; r < cells.rows(); ++r)
    {
        cout << "row : " << r << '\n';
        for (int c = 0; c < cells.cols(); ++c)
        {
            cout << cells(r, c) << " ";
        }

        cout << '\n';
    }

    cout << endl;

    //スペースが押されるまでループ
    for (char c {}; cin >> c && c != ' ';)
        ;

    Console::Close();
}

void Main()
{
    //ConsoleIO();
    

    Window::SetBaseSize(1280, 720);
    ScalableWindow::Setup(1280, 720);
    Window::Resize(800, 450);

    Graphics::SetBackground(Palette::Peachpuff);

    const Font font(30);

    Map2D map {50, 50};
        
    while (System::Update())
    {
        {
            const auto transformer = ScalableWindow::CreateTransformer();
            map.update();
            map.draw();
            
            font(Profiler::FPS()).draw();
        }

        ScalableWindow::DrawBlackBars(Palette::Black);
    }
}