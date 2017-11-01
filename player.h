#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    player (QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent * event);

public slots:
    void spawn();
    void hspawn();

private:
    QMediaPlayer * bulletsound;
    QMediaPlayer * minesound;
};


#endif // PLAYER_H
