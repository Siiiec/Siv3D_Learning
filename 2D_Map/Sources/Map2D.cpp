#include "Map2D.hpp"
#include "Cells\Cells2D.hpp"
#include "Utility\MeasureTime.hpp"


Map2D::Map2D()
    : Map2D(10, 10)
{
    
}

Map2D::Map2D(int rows, int cols)
    : m_rows(rows), m_cols(cols)
{
    using namespace std;

    m_cells = std::make_unique<Cells::Cells2D<int>>(m_rows, m_cols);
    setDrawRegion(Rect(Point {10, 10}, Point {Window::BaseHeight() - 20, Window::BaseHeight() - 20}));
    int cellW = static_cast<int>(oneCellWidth());
    
    //初期テクスチャの追加
    auto t1 = Texture(Image(cellW, cellW, Palette::White));
    m_texAndKey.emplace_back(texAndKey(t1, 0));
    auto t2 = Texture(Image(cellW, cellW, Palette::Black));
    m_texAndKey.emplace_back(texAndKey(t2, 1));
    

    (*m_cells)(0, 3) = 1;

    Graphics2D::SetSamplerState(SamplerState::WrapPoint);
}

Map2D::~Map2D()
{
    Graphics2D::SetSamplerState(SamplerState::Default2D);
}

void Map2D::update()
{
    //クリック判定
    if (m_clickRegion.mouseOver)
    {
        Cursor::SetStyle(CursorStyle::Hand);
        const auto pos = Mouse::Pos() - m_drawRegion.tl;
        const int c = Clamp(static_cast<int>(pos.x / oneCellWidth()), 0, m_cols - 1);
        const int r = Clamp(static_cast<int>(pos.y / oneCellWidth()), 0, m_rows - 1);

        if (Input::MouseL.pressed)
        {
            (*m_cells)(r, c) = m_lmbIndex;
        }
        else if (Input::MouseR.pressed)
        {
            (*m_cells)(r, c) = m_rmbIndex;
        }
    }
    else
    {
        Cursor::SetStyle(CursorStyle::Default);
    }
}

void Map2D::draw() const
{
    double cellWidth = oneCellWidth();


    Utility::MeasureTime t(true);

    RectF dot{0, 0, cellWidth};
    t.measure();
    dot(tex(0, 0)).draw();
    //dot.draw();
    tex(0, 0).draw();
    t.measure();
    dot.drawFrame(1.0, 1.0, Palette::Gray);
    t.measure();

    std::vector<Utility::MeasureTime::timer::duration> times;
    for (int i = 0; i <= 2; ++i)
        times.push_back(t.getDuration(i));

    for (const auto& i : step({0, 0}, {m_cols, m_rows}))
    {
        RectF dot { m_drawRegion.tl.x + i.x * cellWidth, m_drawRegion.tl.y + i.y * cellWidth, cellWidth};
        dot(tex(i.y, i.x)).draw();
        dot.drawFrame(1.0, 1.0, Palette::Gray);
    }
}

void Map2D::resize(int rows, int cols)
{
    m_rows = rows;
    m_cols = cols;
    setDrawRegion(m_drawRegion);
}

Rect Map2D::drawRegion() const
{
    return m_drawRegion;
}

void Map2D::setDrawRegion(const Rect& rect)
{
    m_drawRegion = RectF(rect);
    auto cellW = oneCellWidth();
    m_clickRegion = RectF(m_drawRegion.tl, cellW * m_cols, cellW * m_rows);
}




inline double Map2D::oneCellWidth() const
{
    if (m_rows > m_cols)
    {
        return m_drawRegion.h / m_rows;
    }
    else
    {
        return m_drawRegion.h / m_cols;
    }
}


inline int Map2D::gridSize() const
{
    return m_rows * m_cols;
}


inline Texture& Map2D::tex(int r, int c)
{
    return m_texAndKey[(*m_cells)(r, c)].first;
}

inline Texture Map2D::tex(int r, int c) const
{
    return m_texAndKey[(*m_cells)(r, c)].first;
}

inline int& Map2D::key(int r, int c)
{
    return m_texAndKey[(*m_cells)(r, c)].second;
}

inline int Map2D::key(int r, int c) const
{
    return m_texAndKey[(*m_cells)(r, c)].second;
}