#pragma once

#include "../binary_state.h"
#include <memory>
#include <vector>

using BinaryField = std::vector<std::vector<BinaryState*>>;

struct StateDiff {
    BinaryState previous;
    BinaryState updated;
    int rowIndex;
    int columnIndex;
};

class IGameStateUpdater {
public:
    virtual std::vector<StateDiff> updateState(const BinaryField& playingField) = 0;
};
