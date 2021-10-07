#include "game_state.h"

GameState::GameState(int rows, int columns) : _rowCount(rows), _columnCount(columns)
{

}

void GameState::setGameState(const PlayingField& updatedField)
{
    _cellsStates = updatedField;
}

PlayingField GameState::currentState() const
{
    return _cellsStates;
}

void GameState::nextIteration()
{

}