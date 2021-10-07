#pragma once

enum class CellState
{
    Dead,
    Alive
};

class LifeCell
{
public:
    LifeCell();
    explicit LifeCell(CellState initState);
    void enable();
    void disable();
    CellState state();
private:
    CellState _state;
};