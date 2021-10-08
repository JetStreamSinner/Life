#include "main_window.h"

#include <QGraphicsView>
#include "life_game.h"

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
    } catch (std::bad_alloc& ) {
        std::terminate();
    }
    setCentralWidget(_view);
}
