#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>

Game::Game(int lives, int difficulty, QWidget *parent) : QGraphicsView(parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(Qt::black));
    //setBackgroundBrush(QBrush(QImage(":/images/bg.png")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health(lives);
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    // create the player
    player = new Player();
    player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    connect(player, SIGNAL(increaseScore()), score, SLOT(increase()));
    // add the player to the scene
    scene->addItem(player);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(spawn()));
    timer->start(2000);

    show();
}

void Game::spawn(){
    Enemy *enemy = new Enemy();
    connect(enemy, SIGNAL(lowerHealth()), health, SLOT(decrease()));
    scene->addItem(enemy);
}
