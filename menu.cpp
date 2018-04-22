#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    connect(ui->quitButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_startButton_clicked()
{
    Game *game;
    game = new Game(lives, difficulty);
    game->show();
    close();
}

void Menu::on_settingsButton_clicked()
{
    Settings *settings = new Settings();
    connect(settings, SIGNAL(returnValues(int,int)), this, SLOT(returnValues(int,int)));
    settings->show();
}

void Menu::returnValues(int lives, int difficulty) {
    this->lives = lives;
    this->difficulty = difficulty;
}
