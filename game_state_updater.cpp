#include "game_state_updater.h"
#include <algorithm>

bool LifeGameStateUpdater::cellExist(int rowIndex, int columnIndex, int rowCount, int columnCount) const
{
    bool rowIndexValid = rowIndex >= 0 && rowIndex < rowCount;
    bool columnIndexValid = columnIndex >= 0 && columnIndex < columnCount;
    return rowIndexValid && columnIndexValid;
}

int LifeGameStateUpdater::aliveNeighborsCount(const BinaryField& playingField, int targetRowIndex, int targetColumnIndex) const
{
    const auto rowCount = playingField.size();
    const auto columnCount = playingField.at(0).size();

    auto leftBound = targetColumnIndex - 1;
    auto rightBound = targetColumnIndex + 1;
    const auto topBound = targetRowIndex - 1;
    auto bottomBound = targetRowIndex + 1;

    auto neighborsCounter = 0;

    // left to right
    for (auto index = leftBound; index <= rightBound; ++index)
        if (cellExist(topBound, index, rowCount, columnCount))
            neighborsCounter += playingField.at(topBound).at(index)->state() == StateHolder::Enable;

    // top to bottom
    for (auto index = topBound + 1; index <= bottomBound; ++index)
        if (cellExist(index, rightBound, rowCount, columnCount))
            neighborsCounter += playingField.at(index).at(rightBound)->state() == StateHolder::Enable;

    // right to left
    for (auto index = rightBound - 1; index >= leftBound; --index)
        if (cellExist(bottomBound, index, rowCount, columnCount))
            neighborsCounter += playingField.at(bottomBound).at(index)->state() == StateHolder::Enable;

    // bottom to top
    for (auto index = bottomBound - 1; index > topBound; --index)
        if (cellExist(index, leftBound, rowCount, columnCount))
            neighborsCounter += playingField.at(index).at(leftBound)->state() == StateHolder::Enable;
    return neighborsCounter;
}

std::vector<StateDiff> LifeGameStateUpdater::updateState(const BinaryField& playingField)
{
    static const auto lowBoundAliveCondition = 2;
    static const auto upperBoundAliveCondition = 3;

    const auto rowCount = playingField.size();
    const auto columnCount = playingField.at(0).size();

    std::vector<StateDiff> stateDiffs;
    for (auto rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
        for (auto columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
            const auto neighborsCount = aliveNeighborsCount(playingField, rowIndex, columnIndex);

            const auto previousState = *playingField.at(rowIndex).at(columnIndex);
            const auto updatedState = [neighborsCount, previousState]() {
                if (previousState.state() == StateHolder::Enable) {
                    if (neighborsCount >= lowBoundAliveCondition && neighborsCount <= upperBoundAliveCondition) {
                        return BinaryState(StateHolder::Enable);
                    } else {
                        return BinaryState(StateHolder::Disable);
                    }
                } else {
                    if (neighborsCount == upperBoundAliveCondition) {
                        return BinaryState(StateHolder::Enable);
                    } else {
                        return BinaryState(StateHolder::Disable);
                    };
                }
            }();

            if (previousState != updatedState) {
                StateDiff diff;
                diff.previous = previousState;
                diff.updated = updatedState;
                diff.rowIndex = rowIndex;
                diff.columnIndex = columnIndex;
                stateDiffs.push_back(diff);
            }
        }
    }

    return stateDiffs;
}