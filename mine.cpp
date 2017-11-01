#include "mine.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include <typeinfo>
#include "game.h"

extern game * Game;

mine::mine(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/images/resources/mine.png"));

    QTimer * timer = new QTimer();

    connect(timer, SIGNAL(timeout()),this,SLOT(place()));

    timer->start(50);
}

void mine::place(){

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i])) == typeid(enemy)){

            explosionsound = new QMediaPlayer();
            explosionsound->setMedia(QUrl("qrc:/sounds/resources/mexplosion.mp3"));
            if(explosionsound->state() == QMediaPlayer::PlayingState){
                explosionsound->setPosition(0);
            }
            else if(explosionsound->state() == QMediaPlayer::StoppedState){
                explosionsound->play();
            }
            Game->Score->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    setPos(x(),y());
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
