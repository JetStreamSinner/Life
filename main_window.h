#pragma once

#include <QMainWindow>

class LifeGame;
class QGraphicsView;
class InputsWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QMainWindow * parent = nullptr);
private:
    void initUI();

    InputsWidget * _inputsWidget;
    QGraphicsView * _view;
    LifeGame * _game;
};
