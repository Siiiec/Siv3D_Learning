#pragma once

#include <Siv3D.hpp>
//#include <Cells\Cells2D.hpp>

namespace Cells
{
    template <class T>
    class Cells2D;
}

class Map2D
{
public:
    using texAndKey = std::pair<Texture, int>;

public:
    Map2D();
    Map2D(int rows, int cols);

    ~Map2D();

    void update();
    void draw() const;
    void resize(int rows, int cols);
    
    Rect drawRegion() const;
    void setDrawRegion(const Rect& rect);

private:
    int m_rows;
    int m_cols;
    int m_lmbIndex = 1;
    int m_rmbIndex = 0;


    std::vector<texAndKey> m_texAndKey;

    Rect m_drawRegion;
    std::unique_ptr<Cells::Cells2D<int>> m_cells;

private:
    double oneCellWidth() const;
    int gridSize() const;
    Texture& tex(int r, int c);
    Texture tex(int r, int c) const;
    int& key(int r, int c);
    int key(int r, int c) const;
};