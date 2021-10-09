#pragma once

#include <QWidget>
#include <QLineEdit>

class QPushButton;
class LifeGameOptions;

class InputsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InputsWidget(QWidget * parent=nullptr);

    LifeGameOptions options() const;
signals:
    void startGame();
    void stopGame();
    void settingsChanged();

private:
    void initUI();

    QPushButton * _startGameButton;
    QPushButton * _stopGameButton;

    int _rowCount = 0;
    int _columnCount = 0;

    QLineEdit * _rowCountInput;
    QLineEdit * _columnCountInput;
};
