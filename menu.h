#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "Game.h"
#include "settings.h"

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private slots:
    void on_startButton_clicked();
    void on_settingsButton_clicked();
    void returnValues(int, int);

private:
    Ui::Menu *ui;
    int lives;
    int difficulty;
};

#endif // MENU_H
