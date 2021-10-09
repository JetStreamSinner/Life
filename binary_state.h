#pragma once

enum class StateHolder
{
    Enable,
    Disable
};

class BinaryState
{
public:
    BinaryState();
    explicit BinaryState(StateHolder initState);
    void enable();
    void disable();
    StateHolder state() const;

    bool operator==(const BinaryState &rhs) const;
    bool operator!=(const BinaryState &rhs) const;
private:
    StateHolder _currentState;
};