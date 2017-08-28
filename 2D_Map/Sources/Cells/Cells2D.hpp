#pragma once

#include <vector>
#include <type_traits>

namespace Cells
{

    template <class T>
    class Cells2D
    {
    public:
        static_assert(std::is_default_constructible<T>::value, "Template parameter T is not default constructible.");


        Cells2D(size_t row, size_t col);
        
        
        auto begin() { return m_cells.begin(); }
        auto end() { return m_cells.end(); }
        
    #pragma region コメントアウト
        //template <class F, class Cond>
        //void foreach(F f, Cond cond);
        //template <class F, class Cond>
        //void foreach(F f, Cond cond) const;

        //template <class F>
        //void foreach(F f);
        //template <class F>
        //void foreach(F f) const;
    #pragma endregion
        
        
        T& operator()(size_t row, size_t col);
        T& operator()(size_t row, size_t col) const;
        
        Cells2D resize(size_t newRowSize, size_t newColSize, bool copy = false);

        //全要素数
        size_t size() const noexcept;
        //行数
        size_t rows() noexcept;
        //列数
        size_t cols() noexcept;


    private:
        std::vector<T> m_cells;
        size_t m_rows;
        size_t m_cols;

    };

}


#include "impl\Cells2D_impl.ipp"