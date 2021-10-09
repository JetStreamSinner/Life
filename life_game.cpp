#include "life_game.h"
#include "life_game_graphics_rect.h"

#include <QTimer>

LifeGame::LifeGame(QObject* parent)
    : QGraphicsScene(parent)
    , _gameTimer(nullptr)
    , _updater(std::make_unique<LifeGameStateUpdater>())
{
    initTimer();

    static LifeGameOptions defaultOptions;
    defaultOptions.rowCount = 10;
    defaultOptions.columnCount = 10;
    initGame(defaultOptions);
}

LifeGame::LifeGame(const LifeGameOptions& options, QObject* parent)
    : LifeGame(parent)
{
    initGame(options);
}

void LifeGame::setOptions(const LifeGameOptions& options)
{
    stop();
    resetGame();

    initGame(options);
}

void LifeGame::start()
{
    if (_gameTimer)
        _gameTimer->start();
    else
        // TODO Handler error
        std::terminate();
}

void LifeGame::stop()
{
    if (_gameTimer)
        _gameTimer->stop();
    else
        // TODO Handle error
        std::terminate();
}

void LifeGame::updateState()
{
    if (_updater) {
        auto diffs = _updater->updateState(_playingField);
        for (auto& diff : diffs) {
            const auto targetState = _playingField.at(diff.rowIndex).at(diff.columnIndex);
            if (diff.updated.state() == StateHolder::Enable)
                targetState->enable();
            else
                targetState->disable();
        }
        update();
    } else {
        std::terminate();
    }
}

bool LifeGame::validateOptions(const LifeGameOptions& options) const
{
    bool fieldHasRows = options.rowCount > 0;
    if (fieldHasRows) {
        bool fieldHasColumns = options.columnCount > 0;
        if (!fieldHasColumns)
            return false;
    } else {
        return false;
    }
    return true;
}

void LifeGame::resetGame()
{
    stop();
    // Clear graphics scene
    clear();
    // Clear bit field
    _playingField.clear();
}

void LifeGame::initGame(const LifeGameOptions& options)
{
    bool optionsValid = validateOptions(options);
    if (optionsValid) {
        const auto rowCount = options.rowCount;
        const auto columnCount = options.columnCount;

        _playingField.resize(rowCount);
        std::for_each(_playingField.begin(), _playingField.end(), [&](auto& row) {
            row.resize(columnCount);
        });

        for (auto rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
            for (auto columnIndex = 0; columnIndex < columnCount; ++columnIndex) {

                // TODO Put in options
                static const auto rectWidth = 10;
                static const auto rectHeight = 10;

                const auto x = columnIndex * rectWidth;
                const auto y = rowIndex * rectHeight;
                const QRectF rect(x, y, rectWidth, rectHeight);

                auto* graphicsItem = new LifeGameGraphicsRect(rect, StateHolder::Disable);
                addItem(graphicsItem);
                _playingField.at(rowIndex).at(columnIndex) = graphicsItem;
            }
        }
    } else {
        // TODO Handler error
    }
}

void LifeGame::initTimer()
{
    _gameTimer = new QTimer;
    static const auto defaultUpdateInterval = 100;
    _gameTimer->setInterval(defaultUpdateInterval);

    connect(_gameTimer, &QTimer::timeout, this, [this]() {
        updateState();
    });
}
