#include "healthplus.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include "game.h"

extern game * Game;

healthplus::healthplus(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)  {
    int random_num = rand() % 700;
    setPos(random_num,0);

    //set hplus
    setPixmap(QPixmap(":/images/resources/hplus.png"));


    QTimer * timer = new QTimer();

    connect(timer, SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void healthplus::move()
{
    setPos(x(),y()+20);
    if (pos().y() > 600){
        scene()->removeItem(this);
        delete this;
    }
}
