#include "inputs_widget.h"

#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

#include "life_game.h"

InputsWidget::InputsWidget(QWidget* parent)
    : QWidget(parent)
    , _startGameButton(nullptr)
    , _stopGameButton(nullptr)
{
    initUI();
}

void InputsWidget::initUI()
{
    QGroupBox* gameStatusControls = nullptr;
    QHBoxLayout* gameStatusLayout = nullptr;

    QGroupBox* fieldSettingControls = nullptr;
    QVBoxLayout* fieldSettingLayout = nullptr;

    try {

        // Game status controls
        gameStatusControls = new QGroupBox;
        gameStatusLayout = new QHBoxLayout;

        _startGameButton = new QPushButton("Start");
        _stopGameButton = new QPushButton("Stop");

        gameStatusLayout->addWidget(_startGameButton);
        gameStatusLayout->addWidget(_stopGameButton);
        gameStatusControls->setLayout(gameStatusLayout);

        fieldSettingControls = new QGroupBox;
        fieldSettingLayout = new QVBoxLayout;

        // Game options controls
        auto* rowCountLabel = new QLabel("Rows count");
        _rowCountInput = new QLineEdit;
        auto* rowsCountForm = new QHBoxLayout;
        rowsCountForm->addWidget(rowCountLabel);
        rowsCountForm->addWidget(_rowCountInput);

        auto* columnCountLabel = new QLabel("Column count");
        _columnCountInput = new QLineEdit;
        auto* columnsCountForm = new QHBoxLayout;
        columnsCountForm->addWidget(columnCountLabel);
        columnsCountForm->addWidget(_columnCountInput);

        auto* acceptOptionsButton = new QPushButton("Accept");

        connect(acceptOptionsButton, &QPushButton::clicked, this, [this]() {
            _rowCount = _rowCountInput->text().toInt();
            _columnCount = _columnCountInput->text().toInt();
            emit settingsChanged();
        });

        fieldSettingLayout->addLayout(rowsCountForm);
        fieldSettingLayout->addLayout(columnsCountForm);
        fieldSettingLayout->addWidget(acceptOptionsButton);
        fieldSettingControls->setLayout(fieldSettingLayout);

    } catch (std::bad_alloc& exception) {
        std::terminate();
    }

    auto* layout = new QVBoxLayout;
    layout->addWidget(gameStatusControls);
    layout->addWidget(fieldSettingControls);

    setLayout(layout);

    connect(_startGameButton, &QPushButton::clicked, this, [&]() { emit startGame(); });
    connect(_stopGameButton, &QPushButton::clicked, this, [&]() { emit stopGame(); });
}

LifeGameOptions InputsWidget::options() const
{
    LifeGameOptions options;
    options.rowCount = _rowCount;
    options.columnCount = _columnCount;
    return options;
}
