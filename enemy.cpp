#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include "game.h"

extern game * Game;

enemy::enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)  {
    //random enemy spawn location
    int random_num = rand() % 700;
    setPos(random_num,0);

    //set enemy image and rotation
    setPixmap(QPixmap(":/images/resources/enemy.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);

    QTimer * timer = new QTimer();

    connect(timer, SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void enemy::move()
{
    setPos(x(),y()+5);
    if (pos().y() > 600){

        Game->Health->decrease();

        explosionsound = new QMediaPlayer();
        explosionsound->setMedia(QUrl("qrc:/sounds/resources/powerdown.mp3"));
        if(explosionsound->state() == QMediaPlayer::PlayingState){
            explosionsound->setPosition(0);
        }
        else if(explosionsound->state() == QMediaPlayer::StoppedState){
            explosionsound->play();
        }

        scene()->removeItem(this);
        delete this;
    }
}
