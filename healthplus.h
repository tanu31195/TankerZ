#ifndef HEALTHPLUS_H
#define HEALTHPLUS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class healthplus : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    healthplus(QGraphicsItem * parent=0);

public slots:
    void move();
};


#endif // HEALTHPLUS_H
