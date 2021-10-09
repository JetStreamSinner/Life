#include <QPainter>
#include <QDebug>
#include "life_game_graphics_rect.h"

LifeGameGraphicsRect::LifeGameGraphicsRect(const QRectF &cellRect, StateHolder initState) : QGraphicsRectItem(cellRect), BinaryState(initState)
{

}

void LifeGameGraphicsRect::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget * widget)
{
    QGraphicsRectItem::paint(painter, option, widget);
    const auto brushColor = state() == StateHolder::Enable ? defaultActiveCellColor : defaultInactiveCellColor;
    auto rectBoundaries = boundingRect();
    rectBoundaries.adjust(1, 1, -1, -1);

    painter->fillRect(rectBoundaries, brushColor);
}
void LifeGameGraphicsRect::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsItem::mousePressEvent(event);
    if (state() == StateHolder::Enable)
        disable();
    else
        enable();
    update();
}
