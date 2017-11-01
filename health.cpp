#include "health.h"
#include <QFont>
//#include <QDebug>

health::health(QGraphicsItem *parent) : QGraphicsTextItem(parent) {

    // starting health
    playerHealth = 3;

    setPlainText(QString("Health: ") + QString::number(playerHealth));
    setDefaultTextColor(Qt::red);
    setFont(QFont("arial", 16));
}

void health::increase() {
    playerHealth++;
    setPlainText(QString("Health: ") + QString::number(playerHealth));
}

void health::decrease() {
    playerHealth--;
    setPlainText(QString("Health: ") + QString::number(playerHealth));

    //when health is 0 signal dead is emitted
    if (playerHealth == 0 )
        emit dead();
}

int health::getHealth()
{
    return playerHealth;
}

