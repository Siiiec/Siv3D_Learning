#pragma once

#include <Siv3D.hpp>



class Map2D
{
public:
    Map2D(int rows, int cols)
        : m_rows(rows), m_cols(cols)
    {
        Graphics2D::SetSamplerState(SamplerState::WrapPoint);

        Image image(m_gridSize, m_gridSize, Palette::White);
        texture = DynamicTexture(image);
    }

    ~Map2D()
    {
        Graphics2D::SetSamplerState(SamplerState::Default2D);
    }

    void update()
    {
        using f3 = const char*(*[3][2])(const char*, size_t, bool(*)(char, size_t));
    }

    void draw() const
    {
        texture.scale(m_gridSize).draw(10, 10);

        for (const auto& i : step({0, 0}, {m_cols, m_rows}))
        {
            Rect dot {10 + m_gridSize + i.x * m_gridSize, 10 + i.y * m_gridSize, m_gridSize};
            dot.drawFrame(1.0, 1.0, Palette::Gray);
        }
    }

    void resize(int rows, int cols)
    {
        m_rows = rows;
        m_cols = cols;
    }


private:
    int m_gridSize = 10;
    int m_rows = 10;
    int m_cols = 10;
    
    DynamicTexture texture;

};