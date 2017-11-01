#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
//#include <game.h>

class health: public QGraphicsTextItem {
    Q_OBJECT

public:
    health(QGraphicsItem * parent = 0);
    void increase();
    void decrease();
    int getHealth();

signals:
    void dead();

private:
    int playerHealth;
};

#endif // HEALTH_H
