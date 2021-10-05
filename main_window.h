#pragma once

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>

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
