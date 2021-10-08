#pragma once

#include <memory>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "game_state.h"

class LifeGame : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit LifeGame(QObject * parent=nullptr);

private:
    // TODO Move this in configuration/options
    static const int defaultRowsCount = 10;
    static const int defaultColumnsCount = 10;

    void initGame();
    std::vector<QGraphicsRectItem*> makeGraphicsCellsFromState(const GameState &state) const;

    std::vector<QGraphicsRectItem*> _graphicsCells;
    std::unique_ptr<GameState> _gameState;
};
