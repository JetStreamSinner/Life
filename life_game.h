#pragma once

#include "game_state_updater.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <memory>

struct LifeGameOptions {
    int rowCount = 0;
    int columnCount = 0;
};

class QTimer;

class LifeGame : public QGraphicsScene {
    Q_OBJECT
public:
    explicit LifeGame(QObject* parent = nullptr);
    explicit LifeGame(const LifeGameOptions& options = LifeGameOptions(), QObject* parent = nullptr);

    void setOptions(const LifeGameOptions& options);
    void start();
    void stop();

private:
    void updateState();

    // TODO Move this in configuration/options
    static const int defaultRowsCount = 10;
    static const int defaultColumnsCount = 10;

    bool validateOptions(const LifeGameOptions& options) const;

    void resetGame();
    void initGame(const LifeGameOptions& options);
    void initTimer();

    QTimer* _gameTimer;

    std::unique_ptr<IGameStateUpdater> _updater;
    BinaryField _playingField;
};
