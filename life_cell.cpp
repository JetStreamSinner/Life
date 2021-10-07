#include "life_cell.h"

LifeCell::LifeCell() : _state(CellState::Dead)
{

}

LifeCell::LifeCell(CellState initState) : _state(initState)
{

}

void LifeCell::enable()
{
    _state = CellState::Alive;
}

void LifeCell::disable()
{
    _state = CellState::Dead;
}

CellState LifeCell::state()
{
    return _state;
}