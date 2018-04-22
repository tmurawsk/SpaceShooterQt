#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
    Q_OBJECT

public:
    Health(int lives, QGraphicsItem *parent = 0);
    //void decrease();
    int getHealth();

public slots:
    void decrease();

private:
    int health;
};

#endif // HEALTH_H
