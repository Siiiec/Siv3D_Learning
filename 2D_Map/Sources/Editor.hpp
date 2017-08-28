#pragma once

#include <Siv3D.hpp>

class Map2D;

class Editor final
{
public:
    Editor();
    ~Editor();


private:
    std::unique_ptr<Map2D> map;
};