#pragma once

#include <vector>
#include "interfaces/i_game_state_updater.h"

class LifeGameStateUpdater : public IGameStateUpdater
{
public:
    std::vector<StateDiff> updateState(const BinaryField &playingField) override;
private:

    bool cellExist(int rowIndex, int columnIndex, int rowCount, int columnCount) const;
    int aliveNeighborsCount(const BinaryField &playingField, int rowIndex, int columnIndex) const;
};