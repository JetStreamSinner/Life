#pragma once

#include <QGraphicsRectItem>
#include <QMouseEvent>
#include "life_cell.h"

class LifeGameGraphicsRect : public QGraphicsRectItem
{
public:
    explicit LifeGameGraphicsRect(const QRectF &cellRect, CellState initState);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;

private:
    // TODO Move this in configuration/options
    const QColor defaultInactiveCellColor = Qt::gray;
    const QColor defaultActiveCellColor = Qt::green;

    CellState _state;
};