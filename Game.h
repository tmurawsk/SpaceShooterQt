#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(int lives, int difficulty, QWidget *parent = 0);

    QGraphicsScene *scene;
    Player *player;
    Score *score;
    Health *health;

private slots:
    void spawn();
};

#endif // GAME_H
