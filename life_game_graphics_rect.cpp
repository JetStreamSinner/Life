#include <QPainter>
#include <QDebug>
#include "life_game_graphics_rect.h"

LifeGameGraphicsRect::LifeGameGraphicsRect(const QRectF &cellRect, CellState initState) : QGraphicsRectItem(cellRect), _state(initState)
{

}

void LifeGameGraphicsRect::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget * widget)
{
    QGraphicsRectItem::paint(painter, option, widget);
    const auto brushColor = _state == CellState::Alive ? defaultActiveCellColor : defaultInactiveCellColor;
    auto rectBoundaries = boundingRect();
    rectBoundaries.adjust(1, 1, -1, -1);

    painter->fillRect(rectBoundaries, brushColor);
}
void LifeGameGraphicsRect::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsItem::mousePressEvent(event);
    _state = _state == CellState::Alive ? CellState::Dead : CellState::Alive;
    update();
}
