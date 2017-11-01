#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>

class bullet : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    bullet(QGraphicsItem *parent=0);

public slots:
    void move();

private:
    QMediaPlayer * explosionsound;
};


#endif // BULLET_H
