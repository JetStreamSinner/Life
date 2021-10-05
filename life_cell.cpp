#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include "life_cell.h"

LifeCell::LifeCell(const QRectF& rect) : QGraphicsRectItem(rect, nullptr),
    _state(CellState::Dead), _aliveColor(0, 0, 0, 0)
{

}

void LifeCell::enable()
{
    _state = CellState::Alive;
}

void LifeCell::disable()
{
    _state = CellState::Dead;
}

void LifeCell::setAliveColor(const QColor& color)
{
    _aliveColor = color;
}

CellState LifeCell::state() const
{
    return _state;
}
void LifeCell::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    QGraphicsRectItem::paint(painter, option, widget);
    if (_state == CellState::Alive)
        painter->fillRect(option->rect, _aliveColor);
}
