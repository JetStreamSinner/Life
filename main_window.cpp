#include "main_window.h"

MainWindow::MainWindow(QMainWindow * parent) : QMainWindow(parent), _scene(nullptr),
    _view(nullptr)
{
    initUI();
}

void MainWindow::initUI()
{
    try {
        _scene = new QGraphicsScene(this);
        _view = new QGraphicsView(_scene);
    } catch (std::bad_alloc& ) {
        std::terminate();
    }
    setCentralWidget(_view);
}
