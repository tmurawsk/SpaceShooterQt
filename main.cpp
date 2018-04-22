#include <QApplication>
#include "Game.h"
#include "menu.h"


int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    app.setApplicationName("Shooter");
    app.setApplicationDisplayName("Shooter");

    Menu *menu = new Menu();
    menu->setWindowTitle("Main menu");
    menu->show();

    return app.exec();
}
