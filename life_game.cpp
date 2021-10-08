#include "life_game.h"
#include "life_game_graphics_rect.h"

LifeGame::LifeGame(QObject* parent) : QGraphicsScene(parent)
{
    initGame();
}

void LifeGame::initGame()
{
    _gameState = std::make_unique<GameState>(defaultRowsCount, defaultColumnsCount);
    _graphicsCells = makeGraphicsCellsFromState(*_gameState);
    for (auto &cellItem : _graphicsCells)
        addItem(cellItem);
}

std::vector<QGraphicsRectItem*> LifeGame::makeGraphicsCellsFromState(const GameState &state) const
{
    const auto playingField = state.currentState();
    const auto rowCount = playingField.size();
    const auto columnCount = playingField.at(0).size();

    const auto cellsCount = rowCount * columnCount;
    std::vector<QGraphicsRectItem*> graphicsItems;
    graphicsItems.reserve(cellsCount);

    // TODO Calculate it from size
    static const auto defaultWidth = 50;
    static const auto defaultHeight = 50;

    for (auto rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
        for (auto columnIndex = 0; columnIndex < columnCount; ++columnIndex) {

            auto x = rowIndex * defaultWidth;
            auto y = columnIndex * defaultHeight;
            auto width = defaultWidth;
            auto height = defaultHeight;

            const QRectF cellRect(x, y, width, height);
            auto * newCell = new LifeGameGraphicsRect(cellRect, CellState::Dead);
            graphicsItems.push_back(newCell);
        }
    }

    return graphicsItems;
}