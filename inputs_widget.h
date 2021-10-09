#pragma once

#include <QWidget>

class QPushButton;

class InputsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InputsWidget(QWidget * parent=nullptr);

signals:
    void startGame();
    void stopGame();

private:
    void initUI();

    QPushButton * _startGameButton;
    QPushButton * _stopGameButton;
};
