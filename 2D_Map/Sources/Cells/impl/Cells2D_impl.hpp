#pragma once

#include "../Cells2D.hpp"

namespace Cells
{
    template <class T>
    Cells2D<T>::Cells2D(size_t row, size_t col)
        : m_rows(row), m_cols(col)
    {
        m_cells = std::vector<T>(m_rows * m_cols);
    }

#pragma region コメントアウト

    //template <class T>
    //template <class F, class Cond>
    //void Cells2D<T>::foreach(F f, Cond cond)
    //{
    //    for (auto& c : m_cells)
    //    {
    //        if (!cond(c))
    //            continue;
    //        f(c);
    //    }
    //}

    //template <class T>
    //template <class F, class Cond>
    //void Cells2D<T>::foreach(F f, Cond cond) const
    //{
    //    for (const auto& c : m_cells)
    //    {
    //        if (!cond(c))
    //            continue;
    //        f(c);
    //    }
    //}

    //template <class T>
    //template <class F>
    //void Cells2D<T>::foreach(F f)
    //{
    //    for (auto& c : m_cells)
    //    {
    //        f(c);
    //    }
    //}

    //template <class T>
    //template <class F>
    //void Cells2D<T>::foreach(F f) const
    //{
    //    for (const auto& c : m_cells)
    //    {
    //        f(c);
    //    }
    //}

#pragma endregion

    template <class T>
    T& Cells2D<T>::operator()(size_t row, size_t col)
    {
        return m_cells[m_cols * row + col];
    }
    
    template <class T>
    T& Cells2D<T>::operator()(size_t row, size_t col) const
    {
        return m_cells[m_cols * row + col];
    }
    

    template <class T>
    Cells2D<T> Cells2D<T>::resize(size_t newRowSize, size_t newColSize, bool copy)
    {
        if (copy)
        {
            auto newCell = std::vector<T>(newRowSize * newColSize);
            for (int y = 0; y < newColSize; ++y)
            {
                for (int x = 0; x < newRowSize; ++x)
                {
                    if (x >= m_cols || y >= ) newCell[y*newRowSize + x] = T {};
                }
            }
            
        }
        else
        {
            m_cells = std::vector<T>(newRowSize * newColSize);
        }

        m_rows = newRowSize;
        m_cols = newColSize;
    }

    //全要素数
    template <class T>
    inline size_t Cells2D<T>::size() const noexcept
    {
        return m_rows * m_cols;
    }

    //行数
    template <class T>
    inline size_t Cells2D<T>::rows() noexcept
    {
        return m_rows;
    }

    //列数
    template <class T>
    inline size_t Cells2D<T>::cols() noexcept
    {
        return m_cols
    }

}