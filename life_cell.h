#pragma once

#include <QGraphicsRectItem>

enum class CellState
{
    Dead,
    Alive
};

class LifeCell : public QGraphicsRectItem
{
public:
    explicit LifeCell(const QRectF &rect);
    void enable();
    void disable();

    void setAliveColor(const QColor &color);

    CellState state() const;

    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget) override;
private:
    CellState _state;
    QColor _aliveColor;
};