#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "healthplus.h"
#include <typeinfo>
#include "game.h"

extern game * Game;

bullet::bullet(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/images/resources/bullet.png"));

    QTimer * timer = new QTimer();

    connect(timer, SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void bullet::move(){

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0, n = colliding_items.size(); i < n; i++){
        //enemy collide with bullet
        if(typeid(*(colliding_items[i])) == typeid(enemy)){

            explosionsound = new QMediaPlayer();
            explosionsound->setMedia(QUrl("qrc:/sounds/resources/explosion.mp3"));
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
        //healthplus collide with bullet
        else if(typeid(*(colliding_items[i])) == typeid(healthplus)){

            explosionsound = new QMediaPlayer();
            explosionsound->setMedia(QUrl("qrc:/sounds/resources/healthup.mp3"));
            if(explosionsound->state() == QMediaPlayer::PlayingState){
                explosionsound->setPosition(0);
            }
            else if(explosionsound->state() == QMediaPlayer::StoppedState){
                explosionsound->play();
            }
            Game->Health->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    //movement and deletion of bullet
    setPos(x(),y()-10);
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
