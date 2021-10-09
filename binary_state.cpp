#include "binary_state.h"

BinaryState::BinaryState() : _currentState(StateHolder::Disable)
{

}

BinaryState::BinaryState(StateHolder initState) : _currentState(initState)
{

}

void BinaryState::enable()
{
    _currentState = StateHolder::Enable;
}

void BinaryState::disable()
{
    _currentState = StateHolder::Disable;
}

StateHolder BinaryState::state() const
{
    return _currentState;
}

bool BinaryState::operator==(const BinaryState& rhs) const
{
    return _currentState == rhs.state();
}

bool BinaryState::operator!=(const BinaryState& rhs) const
{
    return !(*this == rhs);
}