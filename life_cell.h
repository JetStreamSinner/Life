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
    CellState state() const;
private:
    CellState _state;
};