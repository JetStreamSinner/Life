#pragma once

#include <QMainWindow>

class LifeGame;
class QGraphicsView;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QMainWindow * parent = nullptr);
private:
    void initUI();

    QGraphicsView * _view;
    LifeGame * _game;
};
