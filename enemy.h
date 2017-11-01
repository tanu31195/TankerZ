#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class enemy : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    enemy(QGraphicsItem * parent=0);

public slots:
    void move();
private:
    QMediaPlayer * explosionsound;
};


#endif // ENEMY_H
