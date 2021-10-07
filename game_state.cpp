#include <stdexcept>
#include "game_state.h"


GameState::GameState(int rows, int columns) : _rowCount(rows), _columnCount(columns)
{

}

bool GameState::validateState(const PlayingField& field)
{
    bool fieldHasRows = !field.empty();
    if (fieldHasRows) {
        const auto firstRowIndex = 0;
        bool fieldHasColumns = !field.at(firstRowIndex).empty();
        if (!fieldHasColumns)
            return false;
    } else {
        return false;
    }
    return true;
}

void GameState::setGameState(const PlayingField& updatedField)
{
    bool stateValid = validateState(updatedField);
    if (!stateValid)
        throw std::logic_error("Wrong field size.");

    _rowCount = updatedField.size();
    const auto firstRowIndex = 0;
    _columnCount = updatedField.at(firstRowIndex).size();

    _cellsStates = updatedField;
}

PlayingField GameState::currentState() const
{
    return _cellsStates;
}

void GameState::nextIteration()
{

}