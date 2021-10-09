#pragma once

#include "binary_state.h"
#include <QGraphicsRectItem>
#include <QMouseEvent>

class LifeGameGraphicsRect : public QGraphicsRectItem,
                             public BinaryState {
public:
    explicit LifeGameGraphicsRect(const QRectF& cellRect, StateHolder initState);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

private:
    // TODO Move this in configuration/options
    const QColor defaultInactiveCellColor = Qt::gray;
    const QColor defaultActiveCellColor = Qt::green;
};