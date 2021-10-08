#include <stdexcept>
#include <algorithm>
#include "game_state.h"


GameState::GameState(int rows, int columns) : _rowCount(rows), _columnCount(columns)
{
    _cellsStates.resize(_rowCount);
    std::for_each(_cellsStates.begin(), _cellsStates.end(), [&](auto &row) {
        row.resize(_columnCount);
    });
}

bool GameState::validateField(const PlayingField& field) const
{
    bool fieldHasRows = !field.empty();
    if (fieldHasRows) {
        bool fieldHasColumns = !field.at(0).empty();
        if (!fieldHasColumns)
            return false;
    } else {
        return false;
    }
    return true;
}

bool GameState::cellExist(int rowIndex, int columnIndex) const
{
    bool rowIndexValid = rowIndex >= 0 && rowIndex < _rowCount;
    bool columnIndexValid = columnIndex >= 0 && columnIndex < _columnCount;
    return rowIndexValid && columnIndexValid;
}

int GameState::aliveNeighborsCount(int targetRowIndex, int targetColumnIndex) const
{
    const auto baseRowIndex = targetRowIndex - 1;
    const auto baseColumnIndex = targetColumnIndex - 1;

    auto leftBound = 0;
    auto rightBound = 2;
    auto bottomBound = 2;

    auto neighborsCounter = 0;

    // left to right
    const auto topBound = 0;
    for (auto index = leftBound; index <= rightBound; ++index)
        if (cellExist(topBound, index))
            neighborsCounter += _cellsStates.at(topBound).at(index).state() == CellState::Alive;

    // top to bottom
    for (auto index = topBound + 1; index <= bottomBound; ++index)
        if (cellExist(index, rightBound))
            neighborsCounter += _cellsStates.at(index).at(rightBound).state() == CellState::Alive;

    // right to left
    for (auto index = rightBound - 1; index >= leftBound; --index)
        if (cellExist(bottomBound, index))
            neighborsCounter += _cellsStates.at(bottomBound).at(index).state() == CellState::Alive;

    // bottom to top
    for (auto index = bottomBound + 1; index >= leftBound; --index)
        if (cellExist(index, leftBound))
            neighborsCounter += _cellsStates.at(index).at(leftBound).state() == CellState::Alive;

    return neighborsCounter;
}

void GameState::enableCell(int rowIndex, int columnIndex)
{
    if (!cellExist(rowIndex, columnIndex))
        throw std::logic_error("Wrong cell index");
    _cellsStates.at(rowIndex).at(columnIndex).enable();
}

void GameState::disableCell(int rowIndex, int columnIndex)
{
    if (!cellExist(rowIndex, columnIndex))
        throw std::logic_error("Wrong cell index");
    _cellsStates.at(rowIndex).at(columnIndex).disable();
}

CellState GameState::cellState(int rowIndex, int columnIndex) const
{
    if (!cellExist(rowIndex, columnIndex))
        throw std::logic_error("Wrong cell index");
    return _cellsStates.at(rowIndex).at(columnIndex).state();
}

void GameState::setGameState(const PlayingField& updatedField)
{
    bool stateValid = validateField(updatedField);
    if (!stateValid)
        throw std::logic_error("Wrong field size.");

    _rowCount = updatedField.size();
    _columnCount = updatedField.at(0).size();

    _cellsStates = updatedField;
}

PlayingField GameState::currentState() const
{
    return _cellsStates;
}

void GameState::nextIteration()
{
    static const auto aliveCondition = 3;
    PlayingField nextState(_cellsStates);

    for (auto rowIndex = 0; rowIndex < _rowCount; ++rowIndex) {
        for (auto columnIndex = 0; columnIndex < _columnCount; ++columnIndex) {
            auto neighborsCount = aliveNeighborsCount(rowIndex, columnIndex);
            if (neighborsCount == aliveCondition)
                nextState.at(rowIndex).at(columnIndex).enable();
            else
                nextState.at(rowIndex).at(columnIndex).disable();
        }
    }
    _cellsStates = nextState;
}