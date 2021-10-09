#include "main_window.h"

#include <QGraphicsView>
#include <QHBoxLayout>

#include "life_game.h"
#include "inputs_widget.h"

MainWindow::MainWindow(QMainWindow * parent) : QMainWindow(parent), _game(nullptr),
    _view(nullptr)
{
    resize(800, 600);
    initUI();
}

void MainWindow::initUI()
{
    try {
        _game = new LifeGame(this);
        _view = new QGraphicsView(_game);
        _inputsWidget = new InputsWidget(this);
    } catch (std::bad_alloc& ) {
        std::terminate();
    }

    auto * compositorLayout = new QHBoxLayout;
    compositorLayout->addWidget(_view);
    compositorLayout->addWidget(_inputsWidget);

    auto * compositor = new QWidget(this);
    compositor->setLayout(compositorLayout);

    setCentralWidget(compositor);

    connect(_inputsWidget, &InputsWidget::startGame, this, [&](){ _game->start(); });
    connect(_inputsWidget, &InputsWidget::stopGame, this, [&](){ _game->stop(); });
}
