#pragma once

#include "life_cell.h"
#include <vector>

using PlayingField = std::vector<std::vector<LifeCell>>;

class GameState
{
public:
    explicit GameState(int rows, int column);
    void nextIteration();

    void enableCell(int rowIndex, int columnIndex);
    void disableCell(int rowIndex, int columnIndex);
    CellState cellState(int rowIndex, int columnIndex) const;

    void setGameState(const PlayingField &updatedField);
    PlayingField  currentState() const;

private:

    bool validateField(const PlayingField &field) const;
    bool cellExist(int rowIndex, int columnIndex) const;

    int aliveNeighborsCount(int rowIndex, int columnIndex) const;

    int _rowCount;
    int _columnCount;

    PlayingField _cellsStates;
};