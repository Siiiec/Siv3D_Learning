#include "Editor.hpp"
#include "Map2D.hpp"

Editor::Editor()
{
    map = std::make_unique<Map2D>(20, 20);
}

Editor::~Editor() = default;