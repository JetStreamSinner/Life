#pragma once

#include <QMainWindow>
#include <QGraphicsView>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QMainWindow * parent = nullptr);
private:
    void initUI();

    QGraphicsView * _view;
    QGraphicsScene * _scene;
};
