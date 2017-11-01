#ifndef MINE_H
#define MINE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>

class mine : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    mine(QGraphicsItem *parent=0);

public slots:
    void place();

private:
    QMediaPlayer * explosionsound;
};

#endif // MINE_H
