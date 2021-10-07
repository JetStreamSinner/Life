#pragma once

#include "life_cell.h"
#include <vector>

using PlayingField = std::vector<std::vector<LifeCell>>;

class GameState
{
public:
    explicit GameState(int rows, int column);
    void nextIteration();

    void setGameState(const PlayingField &updatedField);
    PlayingField  currentState() const;

private:
    int _rowCount;
    int _columnCount;

    PlayingField _cellsStates;
};