#include "score.h"
#include <QFont>

score::score(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    // starting player score
    playerScore = 0;

    setPlainText(QString("Score: ") + QString::number(playerScore));
    setDefaultTextColor(Qt::cyan);
    setFont(QFont("arial", 16));
}

void score::increase() {
    playerScore++;
    setPlainText(QString("Score: ") + QString::number(playerScore));

}

int score::getScore()
{
    return playerScore;
}
