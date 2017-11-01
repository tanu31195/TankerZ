#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
#include "enemy.h"
#include "mine.h"
#include "healthplus.h"

player::player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/resources/bullet.mp3"));

    minesound = new QMediaPlayer();
    minesound->setMedia(QUrl("qrc:/sounds/resources/minesound.mp3"));

    setPixmap(QPixmap(":/images/resources/player.png"));
}

// player movements
void player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > 0)
            setPos (x()-10,y());
    }
    else if (event->key() == Qt::Key_Right) {
        if (pos().x() + 100 < 800)
            setPos (x()+10,y());
    }
    if (event->key() == Qt::Key_Up) {
        if (pos().y() > 0)
            setPos (x(),y()-10);
    }
    if (event->key() == Qt::Key_Down) {
        if (pos().y() < 500)
            setPos (x(),y()+10);
    }
    else if (event->key() == Qt::Key_Space) {
        // create bullet and add to scene
        bullet * bul = new bullet();
        bul->setPos(x()+42,y());
        scene()->addItem(bul);

        // play bullet sound
        if(bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if(bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
    }
    else if (event->key() == Qt::Key_M) {
        // create mine and add to scene
        mine * min = new mine();
        min->setPos(x()+42,y()+42);
        scene()->addItem(min);

        // play mine sound
        if(minesound->state() == QMediaPlayer::PlayingState){
            minesound->setPosition(0);
        }
        else if(minesound->state() == QMediaPlayer::StoppedState){
            minesound->play();
        }
    }
}

// spawn enemies
void player::spawn()
{
    enemy * enemies = new enemy();
    scene()->addItem(enemies);
}

//spawn health
void player::hspawn()
{
    healthplus * hp = new healthplus();
    scene()->addItem(hp);
}
