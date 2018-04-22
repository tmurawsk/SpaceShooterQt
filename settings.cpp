#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    connect(ui->livesSlider, SIGNAL(valueChanged(int)), ui->livesValueLabel, SLOT(setNum(int)));
    connect(ui->difficultySlider, SIGNAL(valueChanged(int)), ui->difficultyValueLabel, SLOT(setNum(int)));
    connect(ui->cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_okButton_clicked()
{
    emit returnValues(ui->livesSlider->value(), ui->difficultySlider->value());
    close();
}
