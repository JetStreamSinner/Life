#include "inputs_widget.h"

#include <QPushButton>
#include <QHBoxLayout>

InputsWidget::InputsWidget(QWidget* parent) : QWidget(parent), _startGameButton(nullptr),
    _stopGameButton(nullptr)
{
    initUI();
}

void InputsWidget::initUI()
{
    try {
        _startGameButton = new QPushButton("Start");
        _stopGameButton = new QPushButton("Stop");
    } catch (std::bad_alloc &exception) {
        std::terminate();
    }

    auto * layout = new QHBoxLayout;
    layout->addWidget(_startGameButton);
    layout->addWidget(_stopGameButton);

    setLayout(layout);

    connect(_startGameButton, &QPushButton::clicked, this, [&](){emit startGame();});
    connect(_stopGameButton, &QPushButton::clicked, this, [&](){emit stopGame();});
}
